'''
Ethernet learning switch in Python.

Note that this file currently has the code to implement a "hub"
in it, not a learning switch.  (I.e., it's currently a switch
that doesn't learn.)
'''
import switchyard
from switchyard.lib.userlib import *


def main(net: switchyard.llnetbase.LLNetBase):
    my_interfaces = net.interfaces()
    mymacs = [intf.ethaddr for intf in my_interfaces]
    switch_table = dict() # 交换机自我学习表
    table_capacity = 5 # 交换机表容量设置

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
        if switch_table.__contains__(eth.src) == False: # 若表中没有该表项，则判断表满
            if len(switch_table) >= table_capacity: # 若表满，则删除流量最少的表项
                for mac in list(switch_table):
                    min_mac = list(switch_table.keys())[0]
                    min_packet_number = switch_table[min_mac][1]
                    if switch_table[mac][1] < min_packet_number:
                        min_mac = mac
                        min_packet_number = switch_table[mac][1]
                switch_table.pop(min_mac)
            switch_table[eth.src] = [fromIface, 0] # 添加表项
        else:
            switch_table[eth.src][0] = fromIface # 若表中有该表项，则更新表项端口信息
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
               switch_table[eth.dst][1] = switch_table[eth.dst][1] + 1 # 更新表项流量信息

    net.shutdown()
