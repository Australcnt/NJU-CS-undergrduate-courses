'''
Ethernet learning switch in Python.

Note that this file currently has the code to implement a "hub"
in it, not a learning switch.  (I.e., it's currently a switch
that doesn't learn.)
'''
import switchyard
from switchyard.lib.userlib import *
import time


def main(net: switchyard.llnetbase.LLNetBase):
    my_interfaces = net.interfaces()
    mymacs = [intf.ethaddr for intf in my_interfaces]
    switch_table = dict() # 交换机自我学习表
    timeout_value = 10 # 超时时间设置

    while True:
        try:
            _, fromIface, packet = net.recv_packet()
        except NoPackets:
            continue
        except Shutdown:
            break

        log_debug (f"In {net.name} received packet {packet} on {fromIface}")
        eth = packet.get_header(Ethernet)
        if eth is None:
            log_info("Received a non-Ethernet packet?!")
            return
        for mac in list(switch_table): # 删去超时的表项
            if time.time() - switch_table[mac][1] > timeout_value:
                switch_table.pop(mac)
        switch_table[eth.src] = [fromIface, time.time()] #添加/更新表项
        if eth.dst in mymacs:
            log_info("Received a packet intended for me")  
        else:
            if (eth.dst == 'ff:ff:ff:ff:ff:ff') or (switch_table.get(eth.dst) == None): # 广播
                for intf in my_interfaces:
                    if intf.name != fromIface:
                        log_info (f"Flooding packet {packet} to {intf.name}")
                        net.send_packet(intf, packet)
            else:
               net.send_packet(switch_table[eth.dst][0], packet)

    net.shutdown()
