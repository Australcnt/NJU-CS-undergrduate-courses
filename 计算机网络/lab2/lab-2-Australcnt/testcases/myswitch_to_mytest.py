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
    
    # test case 2: a frame with dest address recorded should only be 
    # sent out to a specific port
    reqpkt = new_packet(
        "20:00:00:00:00:01",
        "30:00:00:00:00:02", 
        "192.168.1.100",
        "172.16.42.2"
    )
    s.expect(
        PacketInputEvent("eth0", reqpkt, display=Ethernet), 
        ("An Ethernet frame from 20:00:00:00:00:01 to "
         "30:00:00:00:00:02 should arrive on eth0")

    )
    s.expect(
        PacketOutputEvent("eth1", reqpkt, display=Ethernet),
        ("Ethernet frame destined for 30:00:00:00:00:02 should be forwarded out "
         "port eth1 because switch remembered it in last transimission")
    ) 
    
    # test case 3: sleep 10s
    s.expect(
        PacketInputTimeoutEvent(10.0),
        "No packet will be forwarded out in 10s"
    )

    # test case 4: after timeout, the record should be removed
    reqpkt = new_packet(
        "20:00:00:00:00:01",
        "30:00:00:00:00:02",
        "192.168.1.100",
        "172.16.42.2"
    )
    s.expect(
        PacketInputEvent("eth0", reqpkt, display=Ethernet),
        ("An Ethernet frame from 20:00:00:00:00:01 to "
         "30:00:00:00:00:02 should arrive on eth0")
    )
    s.expect(
        PacketOutputEvent("eth1", reqpkt,"eth2", reqpkt, display=Ethernet),
        ("Ethernet frame destined for 30:00:00:00:00:02 should be "
         "flooded out eth1 and eth2 because switch forgot it")
    ) 

    return s


scenario = test_switch()
