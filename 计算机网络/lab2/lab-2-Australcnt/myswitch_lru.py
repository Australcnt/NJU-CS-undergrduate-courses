'''
Ethernet learning switch in Python.

Note that this file currently has the code to implement a "hub"
in it, not a learning switch.  (I.e., it's currently a switch
that doesn't learn.)
'''
import switchyard
from switchyard.lib.userlib import *
from collections import OrderedDict


def main(net: switchyard.llnetbase.LLNetBase):
    my_interfaces = net.interfaces()
    mymacs = [intf.ethaddr for intf in my_interfaces]
    switch_table = OrderedDict() # 交换机自我学习表(有序字典，模拟age概念)
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
        
        if switch_table.__contains__(eth.src) == False: # 若表中没有该表项，则检查表满
            if len(switch_table) >= table_capacity: # 若表满，则删除最久没使用的表项
                switch_table.popitem(last = False)
        switch_table[eth.src] = fromIface # 添加表项/更新表项端口信息
        if eth.dst in mymacs:
            log_info("Received a packet intended for me")  
        else:
            if (eth.dst == 'ff:ff:ff:ff:ff:ff') or (switch_table.get(eth.dst) == None): # 广播
                for intf in my_interfaces:
                    if intf.name != fromIface:
                        log_info (f"Flooding packet {packet} to {intf.name}")
                        net.send_packet(intf, packet)
            else:
               net.send_packet(switch_table[eth.dst], packet)
               switch_table.move_to_end(eth.dst) # 更新表项LRU信息

    net.shutdown()
