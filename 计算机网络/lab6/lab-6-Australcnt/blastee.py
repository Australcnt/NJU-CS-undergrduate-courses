#!/usr/bin/env python3

import time
import threading
from struct import pack
import switchyard
from switchyard.lib.address import *
from switchyard.lib.packet import *
from switchyard.lib.userlib import *


class Blastee:
    def __init__(
            self,
            net: switchyard.llnetbase.LLNetBase,
            blasterIp,
            num
    ):
        self.net = net
        # TODO: store the parameters
        self.blasterIp = IPv4Address(blasterIp)
        self.num = int(num)

    def handle_packet(self, recv: switchyard.llnetbase.ReceivedPacket):
        _, fromIface, packet = recv
        log_info(f"I got a packet from {fromIface}")
        log_debug(f"Pkt: {packet}")
        if packet[Ethernet].ethertype != EtherType.IPv4 or (packet[Ethernet].ethertype == EtherType.IPv4 and packet[IPv4].protocol != IPProtocol.UDP):
            log_info('This is not a UDP packet')
            return # 不是UDP包，则忽略
        header = packet.get_header(RawPacketContents)
        seq_num = int.from_bytes(header.data[:4], 'big')
        payload = header.data[6:14]
        if len(payload) < 8: # paylaod长度不足8字节时，则需要补0
            payload += '\0'.encode() * (8 - len(payload))
        # 创建ACK
        ack = Ethernet(ethertype = EtherType.IPv4) + IPv4(protocol = IPProtocol.UDP) + UDP() + seq_num.to_bytes(4, 'big') + payload
        ack[Ethernet].src = EthAddr('20:00:00:00:00:01')
        ack[Ethernet].dst = EthAddr('40:00:00:00:00:02')
        ack[IPv4].src = IPv4Address('192.168.200.1')
        ack[IPv4].dst = self.blasterIp # IPv4Address('192.168.100.1')
        ack[IPv4].ttl = 64
        #ack[UDP].src = 4444
        #ack[UDP].dst = 5555
        ack[UDP].dst = seq_num
        # 发送ACK
        self.net.send_packet('blastee-eth0', ack)
        log_info(f'Send the ACK {seq_num} to blaster')
        
    def start(self):
        '''A running daemon of the blastee.
        Receive packets until the end of time.
        '''
        while True:
            try:
                recv = self.net.recv_packet(timeout=1.0)
            except NoPackets:
                continue
            except Shutdown:
                break

            self.handle_packet(recv)

        self.shutdown()

    def shutdown(self):
        self.net.shutdown()


def main(net, **kwargs):
    blastee = Blastee(net, **kwargs)
    blastee.start()
