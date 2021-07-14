#!/usr/bin/env python3

import time
from random import randint
import switchyard
from switchyard.lib.address import *
from switchyard.lib.packet import *
from switchyard.lib.userlib import *


class Blaster:
    def __init__(
            self,
            net: switchyard.llnetbase.LLNetBase,
            blasteeIp,
            num,
            length="100",
            senderWindow="5",
            timeout="300",
            recvTimeout="100"
    ):
        self.net = net
        # TODO: store the parameters
        self.blasteeIp = IPv4Address(blasteeIp)
        self.num = int(num)
        self.length = int(length)
        self.senderWindow = int(senderWindow)
        self.timeout = float(timeout) / 1000
        self.recvTimeout = float(recvTimeout) / 1000
        
        self.LHS = 1
        self.RHS = 1
        self.ackd = (self.num + 1) * [False] # 当前数据包是否被ACK过
        self.start_time = time.time() # 第一次发送数据包的时间
        self.timer = time.time() # LHS最后被修改的时间
        self.reTX_flag = False # 是否处于重传状态
        self.cur_reTX = 1 # 当前需要被重传的数据包的下标

        self.total_TX_time = 0
        self.reTX_num = 0
        self.coarse_TOs_num = 0
        self.throughput = 0
        self.goodput = 0

    def handle_packet(self, recv: switchyard.llnetbase.ReceivedPacket):
        _, fromIface, packet = recv
        log_debug("I got a packet")
        if packet[Ethernet].ethertype != EtherType.IPv4 or (packet[Ethernet].ethertype == EtherType.IPv4 and packet[IPv4].protocol != IPProtocol.UDP):
            log_info('This is not a UDP packet')
            return True # 不是UDP包，则忽略
        header = packet.get_header(RawPacketContents)
        seq_num = int.from_bytes(header.data[:4], 'big')
        log_info(f'Receive the ACK {seq_num} from blastee')
        if self.ackd[seq_num] == False: # 若该数据包未ACK过，则更新相关信息
            self.ackd[seq_num] = True
            while self.LHS != self.num + 1 and self.ackd[self.LHS] == True:
                self.LHS += 1
                log_info(f'LHS increase: LHS is {self.LHS} and RHS is {self.RHS}')
                self.timer = time.time() # 更新LHS最后被修改的时间
            if self.LHS == self.num + 1: # 若所有的数据包均被ACK过，则计算总传输时间，结束传输
                self.total_TX_time = time.time() - self.start_time
                return False
        return True
    
    def create_packet(self, seq_num):
        packet = Ethernet(ethertype = EtherType.IPv4) + IPv4(protocol = IPProtocol.UDP) + UDP()
        packet[Ethernet].src = EthAddr('10:00:00:00:00:01')
        packet[Ethernet].dst = EthAddr('40:00:00:00:00:01')
        packet[IPv4].src = IPv4Address('192.168.100.1')
        packet[IPv4].dst = self.blasteeIp # IPv4Address('192.168.200.1')
        packet[IPv4].ttl = 64
        #packet[UDP].src = 4444
        #packet[UDP].dst = 5555
        packet[UDP].src = seq_num
        packet += seq_num.to_bytes(4, 'big')
        packet += self.length.to_bytes(2, 'big')
        if not self.reTX_flag:
            packet += 'TX'.ljust(self.length, '0').encode()
        else:
            packet += 'reTX'.ljust(self.length, '0').encode()
        return packet

    def handle_no_packet(self):
        log_debug("Didn't receive anything")

        if self.reTX_flag == False and time.time() - self.timer > self.timeout: # 超时且不处于重传状态
            log_info('Coarse time out')
            self.reTX_flag = True
            self.coarse_TOs_num += 1
            self.cur_reTX = self.LHS # 先重传位于LHS的数据包
            pkt = self.create_packet(self.cur_reTX)
            self.net.send_packet('blaster-eth0', pkt)
            log_info(f'Retransmit the packet with seq_num {self.cur_reTX}')
            self.reTX_num += 1
            self.throughput += self.length
            self.cur_reTX += 1
        else:
            if self.reTX_flag: # 仍处于重传状态，则继续重传剩下的未ACK的数据包
                while self.cur_reTX != self.num + 1 and self.ackd[self.cur_reTX] == True: # 找到剩下的第一个未ACK的数据包
                    self.cur_reTX += 1
                if self.cur_reTX < self.RHS:
                    pkt = self.create_packet(self.cur_reTX)
                    self.net.send_packet('blaster-eth0', pkt)
                    log_info(f'Retransmit the packet with seq_num {self.cur_reTX}')
                    self.reTX_num += 1
                    self.throughput += self.length
                    self.cur_reTX += 1
                    if self.cur_reTX == self.RHS: # 滑动窗口中所有未ACK的数据包均已ACK完毕
                        self.reTX_flag = False
                else:
                    self.reTX_flag = False # 滑动窗口中不存在未ACK的包
            elif self.RHS - self.LHS + 1 <= self.senderWindow: # 满足滑动窗口大小的限制下，发送数据包
                if self.RHS != self.num + 1: # 还未发送完所有数据包
                    pkt = self.create_packet(self.RHS)
                    self.net.send_packet('blaster-eth0', pkt)
                    log_info(f'Transmit the packet with seq_num {self.RHS}')
                    if self.RHS == 1: # 记录发送第一个数据包的时间，作为开始时间
                        self.start_time = time.time()
                    self.throughput += self.length
                    self.goodput += self.length
                    self.RHS += 1
                    log_info(f'RHS increase: LHS is {self.LHS} and RHS is {self.RHS}')

    def start(self):
        '''A running daemon of the blaster.
        Receive packets until the end of time.
        '''
        while True:
            try:
                recv = self.net.recv_packet(timeout=self.recvTimeout)
            except NoPackets:
                self.handle_no_packet()
                continue
            except Shutdown:
                break

            if not self.handle_packet(recv):
                break
            self.handle_no_packet()

        self.shutdown()
        print("Total TX time:", self.total_TX_time)
        print("Number of reTX:", self.reTX_num)
        print("Number of coarse TOs:", self.coarse_TOs_num)
        print("Throughput (Bps):",  self.throughput / self.total_TX_time)
        print("Goodput (Bps):", self.goodput / self.total_TX_time)

    def shutdown(self):
        self.net.shutdown()


def main(net, **kwargs):
    blaster = Blaster(net, **kwargs)
    blaster.start()
