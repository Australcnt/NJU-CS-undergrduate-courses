#!/usr/bin/env python3

from switchyard.lib.userlib import *
import time

def new_packet(hwsrc, hwdst, ipsrc, ipdst, reply=False):
    ether = Ethernet(src=hwsrc, dst=hwdst, ethertype=EtherType.IP)
    ippkt = IPv4(src=ipsrc, dst=ipdst, protocol=IPProtocol.ICMP, ttl=32)
    icmppkt = ICMP()
    if reply:
        icmppkt.icmptype = ICMPType.EchoReply
    else:
        icmppkt.icmptype = ICMPType.EchoRequest
    return ether + ippkt + icmppkt


def test_switch():
    s = TestScenario("switch tests")
    s.add_interface('eth0', '10:00:00:00:00:01')
    s.add_interface('eth1', '10:00:00:00:00:02')
    s.add_interface('eth2', '10:00:00:00:00:03')

    # test case 1: a frame with broadcast destination should get sent out
    # all ports except ingress
    testpkt = new_packet(
        "30:00:00:00:00:02",
        "ff:ff:ff:ff:ff:ff", 
        "172.16.42.2",
        "255.255.255.255"
    )
    s.expect(
        PacketInputEvent("eth1", testpkt, display=Ethernet),
        ("An Ethernet frame with a broadcast destination address "
         "should arrive on eth1")
    )
    s.expect(
        PacketOutputEvent("eth0", testpkt, "eth2", testpkt, display=Ethernet),
        ("The Ethernet frame with a broadcast destination address "
         "should be forwarded out ports eth0 and eth2")
    )

    # test case 2: a frame with unkown dest address should be flooded to 
    # all ports except ingress
    resppkt = new_packet(
        "20:00:00:00:00:01",
        "20:00:00:00:00:03",
	    "192.168.1.100",
	    "192.168.3.100"
    )
    s.expect(
        PacketInputEvent("eth0", resppkt, display=Ethernet),
        ("An Ethernet frame from 20:00:00:00:00:01 to "
         "20:00:00:00:00:03 should arrive on eth0")
    )
    s.expect(
        PacketOutputEvent("eth1", resppkt, "eth2", resppkt, display=Ethernet),
        ("Ethernet frame destined for 20:00:00:00:00:03 should be flooded "
         "out eth1 and eth2 because switch doesn't know dest address")
    )
    
    # test case 3: a frame with unkown dest address should be flooded to 
    # all ports except ingress because lru was removed
    reqpkt = new_packet(
        "20:00:00:00:00:03",
        "30:00:00:00:00:02", 
        "192.168.3.100",
        "172.16.42.2"
    )
    s.expect(
        PacketInputEvent("eth2", reqpkt, display=Ethernet), 
        ("An Ethernet frame from 20:00:00:00:00:03 to "
         "20:00:00:00:00:01 should arrive on eth2")

    )
    s.expect(
        PacketOutputEvent("eth0", reqpkt, "eth1", reqpkt, display=Ethernet),
        ("Ethernet frame destined for 30:00:00:00:00:02 should be flooded "
         "out eth0 and eth1 because switch doesn't know dest address")
    ) 

    return s


scenario = test_switch()
