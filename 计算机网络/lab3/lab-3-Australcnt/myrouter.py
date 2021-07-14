#!/usr/bin/env python3

'''
Basic IPv4 router (static routing) in Python.
'''

import time
import switchyard
from switchyard.lib.userlib import *
cached_table = dict() # cache表
timeout_value = 10 # 超时时间设置

class Router(object):
    def __init__(self, net: switchyard.llnetbase.LLNetBase):
        self.net = net
        # other initialization stuff here

    def handle_packet(self, recv: switchyard.llnetbase.ReceivedPacket):
        timestamp, ifaceName, packet = recv
        # TODO: your logic here
        arp = packet.get_header(Arp)
        for ipaddr in list(cached_table):
            if timestamp - cached_table[ipaddr][1] > timeout_value:
                cached_table.pop(ipaddr)
                log_info("\ncached_table_delete: {}\n".format(cached_table))
        if arp is None:
            pass
        elif arp.operation == ArpOperation.Reply:
            cached_table[arp.senderprotoaddr] = [arp.senderhwaddr, timestamp]
            log_info("\ncached_table_add/update: {}\n".format(cached_table))
        elif arp.operation == ArpOperation.Request:
            for intf in self.net.interfaces():
                if intf.ipaddr == arp.targetprotoaddr:
                    cached_table[arp.senderprotoaddr] = [arp.senderhwaddr, timestamp]
                    log_info("\ncached_table_add/update: {}\n".format(cached_table))
                    new_pkt = create_ip_arp_reply(intf.ethaddr, arp.senderhwaddr, intf.ipaddr, arp.senderprotoaddr)
                    self.net.send_packet(ifaceName, new_pkt)
                    break
                    

    def start(self):
        '''A running daemon of the router.
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
