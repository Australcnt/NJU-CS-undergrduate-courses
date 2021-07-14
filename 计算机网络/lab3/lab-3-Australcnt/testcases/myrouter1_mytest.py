#!/usr/bin/env python3

from switchyard.lib.userlib import *


def new_packet(hwsrc, hwdst, ipsrc, ipdst, reply=False):
    ether = Ethernet(src=hwsrc, dst=hwdst, ethertype=EtherType.IP)
    ippkt = IPv4(src=ipsrc, dst=ipdst, protocol=IPProtocol.ICMP, ttl=32)
    icmppkt = ICMP()
    if reply:
        icmppkt.icmptype = ICMPType.EchoReply
    else:
        icmppkt.icmptype = ICMPType.EchoRequest
    return ether + ippkt + icmppkt

def ArpRequest(s, srcMac, dstMac, srcIp, dstIp, srcInterface):
    testpkt = create_ip_arp_request(srcMac, srcIp, dstIp)
    s.expect(PacketInputEvent(srcInterface, testpkt, display=Ethernet), "(ARP Request) DST IP: {}, arrive on {}".format(dstIp, srcInterface))

    replypkt = create_ip_arp_reply(dstMac, srcMac, dstIp, srcIp)
    s.expect(PacketOutputEvent(srcInterface, replypkt, display=Ethernet), "(ARP Request) DST IP: {}, response from {}".format(dstIp, srcInterface))

def ArpNotRespond(s, srcMac, dstMac, srcIp, dstIp, srcInterface, isArpRqst=False):
    if isArpRqst == False:
        testpkt = new_packet(srcMac, dstMac, srcIp, dstIp)
        s.expect(PacketInputEvent(srcInterface, testpkt, display=Ethernet), "(ICMP NOT Respond) DST IP: {}, arrive on {}".format(dstIp, srcInterface))

    else:
        testpkt = create_ip_arp_request(srcMac, srcIp, dstIp)
        s.expect(PacketInputEvent(srcInterface, testpkt, display=Ethernet), "(ARP NOT Respond) DST IP: {}, arrive on {}".format(dstIp, srcInterface))

def test_router():
    s = TestScenario("router tests")

    s.add_interface('router-eth0', '10:00:00:00:00:01', ipaddr='192.168.1.1')
    s.add_interface('router-eth1', '10:00:00:00:00:02', ipaddr='10.10.0.1')

    host = [
        ["20:00:00:00:00:01", "192.168.1.205", "192.168.1.1"],
        ["20:00:00:00:00:02", "192.168.1.206", "10.10.0.2"],
        ["30:00:00:00:00:01", "192.168.1.207", "10.10.0.1"]
    ]

    ArpRequest(s, host[0][0], '10:00:00:00:00:01', host[0][1], host[0][2], 'router-eth0')

    ArpNotRespond(s, host[1][0], '10:00:00:00:00:02', host[1][1], '10.10.12.34', 'router-eth1')
    
    ArpNotRespond(s, host[1][0], '10:00:00:00:00:02', host[1][1], host[1][2], 'router-eth1', isArpRqst=True)

    ArpRequest(s, host[2][0], '10:00:00:00:00:02', host[2][1], host[2][2], 'router-eth1')

    return s

scenario = test_router()