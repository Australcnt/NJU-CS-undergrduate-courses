#!/usr/bin/env python3

'''
Basic IPv4 router (static routing) in Python.
'''

import time
import switchyard
from switchyard.lib.userlib import *

cached_table = {} # cache表
timeout_value = 10 # 超时时间设置
forwarding_table = [] # 转发表
waiting_queue = [] # 等待队列
dstip_list = [] # 正在通过ARP查询的dstip

class Entry:
    def __init__(self, prefix, mask, nexthop, intfname):
        self.network = IPv4Network(str(prefix) + '/' + str(mask), strict = False)
        self.nexthop = nexthop
        self.intfname = intfname
    
    def __lt__(self, other): # 重定义比较函数
        return self.network.prefixlen > other.network.prefixlen # 确保按前缀长度递减的顺序排序

class Wait:
    def __init__(self, packet, timestamp, interface, dstip, from_intf):
        self.packet = packet # 等待被发送的包
        self.timestamp = timestamp # 上一次发送ARP请求的时间
        self.interface = interface # 发送的端口
        self.dstip = dstip # 下一跳的ip地址
        self.count = 0 # 累计发送ARP请求的次数
        self.from_intf = from_intf

class Router(object):
    def __init__(self, net: switchyard.llnetbase.LLNetBase):
        self.net = net
        # other initialization stuff here
        # 路由器接口
        for intf in self.net.interfaces():
            ipaddr = IPv4Address(int(intf.ipaddr) & int(intf.netmask)) # 通过掩码取出端口的IP地址所在的子网
            forwarding_table.append(Entry(IPv4Address(ipaddr),IPv4Address(intf.netmask), None, intf.name))
        # 读文件
        with open("forwarding_table.txt") as info_file:
            for line in info_file:
                info = line.rsplit() # 切割字符串(从行尾开始切割，以去掉行尾回车）
                if info is None: # 确认不是空行
                    break
                forwarding_table.append(Entry(IPv4Address(info[0]), IPv4Address(info[1]), IPv4Address(info[2]), info[3]))
        # 最长前缀匹配的递减排序
        forwarding_table.sort()
        #for entry in forwarding_table:
        #    print(entry.network, entry.nexthop, entry.intfname)

    def handle_icmp_error(self, intf, packet, errortype, code):
        eth = Ethernet()
        eth.ethertype = EtherType.IPv4

        ipv4 = IPv4()
        ipv4.protocol = IPProtocol.ICMP
        ipv4.src = intf.ipaddr
        ipv4.dst = packet[IPv4].src
        ipv4.ttl = 64 + 1 # 发送时会减1，故ttl先设为65

        icmp = ICMP()
        icmp.icmptype = errortype
        icmp.icmpcode = code
        ethernet_index = packet.get_header_index(Ethernet)
        del packet[ethernet_index]
        icmp.icmpdata.data = packet.to_bytes()[:28]
        icmp.icmpdata.origdgramlen = len(packet)
        
        new_pkt = eth + ipv4 + icmp
        return new_pkt

    def handle_packet(self, recv: switchyard.llnetbase.ReceivedPacket):
        timestamp, ifaceName, packet = recv
        # TODO: your logic here
        eth = packet[Ethernet]
        for ipaddr in list(cached_table): # 删去cached_table中超时的表项
            if timestamp - cached_table[ipaddr][1] > timeout_value:
                cached_table.pop(ipaddr)
                #log_info("\ncached_table_delete: {}\n".format(cached_table))
        if eth.ethertype == EtherType.ARP:
            arp = packet.get_header(Arp)
            if arp.operation == ArpOperation.Reply:
                if arp.senderprotoaddr in dstip_list:
                    dstip_list.remove(arp.senderprotoaddr)
                cached_table[arp.senderprotoaddr] = [arp.senderhwaddr, timestamp]
                #log_info("\ncached_table_add/update: {}\n".format(cached_table))
            elif arp.operation == ArpOperation.Request:
                for intf in self.net.interfaces():
                    if intf.ipaddr == arp.targetprotoaddr:
                        new_pkt = create_ip_arp_reply(intf.ethaddr, arp.senderhwaddr, intf.ipaddr, arp.senderprotoaddr)
                        self.net.send_packet(ifaceName, new_pkt)
                        cached_table[arp.senderprotoaddr] = [arp.senderhwaddr, timestamp]
                        #log_info("\ncached_table_add/update: {}\n".format(cached_table))
                        break
        elif eth.ethertype == EtherType.IPv4:
            if packet[IPv4].dst in [intf.ipaddr for intf in self.net.interfaces()]: # If packet is for the router itself
                icmp = packet.get_header(ICMP)
                if packet[IPv4].protocol == IPProtocol.ICMP and icmp.icmptype == ICMPType.EchoRequest: # 对ICMP request进行回应
                    icmp_reply = ICMP()
                    icmp_reply.icmptype = ICMPType.EchoReply
                    icmp_reply.icmpdata.sequence = icmp.icmpdata.sequence
                    icmp_reply.icmpdata.identifier = icmp.icmpdata.identifier
                    icmp_reply.icmpdata.data = icmp.icmpdata.data
                    icmp_index = packet.get_header_index(ICMP)
                    packet[icmp_index] = icmp_reply
                    packet[IPv4].src, packet[IPv4].dst = packet[IPv4].dst, packet[IPv4].src
                else:
                    if self.net.interface_by_name(ifaceName).ipaddr != packet[IPv4].src:
                        packet = self.handle_icmp_error(self.net.interface_by_name(ifaceName), packet, ICMPType.DestinationUnreachable, 3) # 对非ICMP request反馈错误信息
                    else:
                        return    
            ipv4 = packet.get_header(IPv4)
            match_flag = 0
            for entry in forwarding_table:
                if ipv4.dst in entry.network:
                    match_flag = 1
                    ipv4.ttl -= 1
                    if ipv4.ttl <= 0:
                        packet = self.handle_icmp_error(self.net.interface_by_name(ifaceName), packet, ICMPType.TimeExceeded, 0)
                        self.handle_packet((timestamp, ifaceName, packet))
                        break
                    if entry.nexthop is None:
                        nexthop = ipv4.dst # next hop is the destination
                    else:
                        nexthop = entry.nexthop
                    if nexthop in cached_table:
                        packet[Ethernet].src = self.net.interface_by_name(entry.intfname).ethaddr
                        packet[Ethernet].dst = cached_table[nexthop][0]
                        self.net.send_packet(entry.intfname, packet)
                    else:
                        waiting_queue.append(Wait(packet, time.time(), self.net.interface_by_name(entry.intfname), nexthop, self.net.interface_by_name(ifaceName)))
                    break
            if match_flag == 0: # 没匹配上
                packet = self.handle_icmp_error(self.net.interface_by_name(ifaceName), packet, ICMPType.DestinationUnreachable, 0)
                self.handle_packet((timestamp, ifaceName, packet))
        else:
            pass  

    def start(self):
        '''A running daemon of the router.
        Receive packets until the end of time.
        '''
        while True:
            to_delete = [] # 等待队列中将要删除的包
            for wait in waiting_queue:
                if wait.dstip in cached_table:
                    wait.packet[Ethernet].src = wait.interface.ethaddr
                    wait.packet[Ethernet].dst = cached_table[wait.dstip][0]
                    self.net.send_packet(wait.interface.name, wait.packet)
                    to_delete.append(wait)
                elif time.time() - wait.timestamp >= 1: # 距离上次发送ARP请求超过1秒
                    if wait.count < 5: # 发送ARP请求不超过5次，则发送ARP请求，更新相关信息
                        if wait.dstip not in dstip_list or wait.count > 0:
                            arppkt = create_ip_arp_request(wait.interface.ethaddr, wait.interface.ipaddr, wait.dstip)
                            self.net.send_packet(wait.interface.name, arppkt)
                            if wait.count == 0:
                                dstip_list.append(wait.dstip)
                            wait.timestamp = time.time()
                            wait.count += 1     
                    else: # 发送ARP请求达到5次，则丢弃该包
                        dstip_list.remove(wait.dstip) 
                        for samedst_wait in waiting_queue:
                            if samedst_wait.dstip == wait.dstip:
                                to_delete.append(samedst_wait)
                                packet = self.handle_icmp_error(samedst_wait.from_intf, samedst_wait.packet, ICMPType.DestinationUnreachable, 1)
                                self.handle_packet((samedst_wait.timestamp, samedst_wait.from_intf.name, packet))     
            for deletewait in to_delete:
                waiting_queue.remove(deletewait)

            try:
                recv = self.net.recv_packet(timeout=1.0)
            except NoPackets:
                continue
            except Shutdown:
                break

            self.handle_packet(recv)
            
        self.stop()

    def stop(self):
        self.net.shutdown()


def main(net):
    '''
    Main entry point for router.  Just create Router
    object and get it going.
    '''
    router = Router(net)
    router.start()
