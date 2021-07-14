'''DNS Server for Content Delivery Network (CDN)
'''

import sys
from socketserver import UDPServer, BaseRequestHandler
from utils.dns_utils import DNS_Request, DNS_Rcode
from utils.ip_utils import IP_Utils
from datetime import datetime
import math
from random import randint
import fnmatch

import re
from collections import namedtuple


__all__ = ["DNSServer", "DNSHandler"]

class Entry:
    def __init__(self, domain_name, record_type, record_values):
        self.domain_name = domain_name
        self.record_type = record_type
        self.record_values = record_values

class DNSServer(UDPServer):
    def __init__(self, server_address, dns_file, RequestHandlerClass, bind_and_activate=True):
        super().__init__(server_address, RequestHandlerClass, bind_and_activate=True)
        self._dns_table = []
        self.parse_dns_file(dns_file)
        
    def parse_dns_file(self, dns_file):
        # ---------------------------------------------------
        # TODO: your codes here. Parse the dns_table.txt file
        # and load the data into self._dns_table.
        
        with open(dns_file) as info_file:
            for line in info_file:
                info = line.rsplit() # 切割字符串(从行尾开始切割，以去掉行尾回车）
                if info is None: # 确认不是空行
                    break
                self._dns_table.append(Entry(info[0], info[1], info[2:]))
        for entry in self._dns_table:
            print(entry.domain_name, entry.record_type, entry.record_values)

        # --------------------------------------------------
    @property
    def table(self):
        return self._dns_table


class DNSHandler(BaseRequestHandler):
    """
    This class receives clients' udp packet with socket handler and request data. 
    ----------------------------------------------------------------------------
    There are several objects you need to mention:
    - udp_data : the payload of udp protocol.
    - socket: connection handler to send or receive message with the client.
    - client_ip: the client's ip (ip source address).
    - client_port: the client's udp port (udp source port).
    - DNS_Request: a dns protocl tool class.
    We have written the skeleton of the dns server, all you need to do is to select
    the best response ip based on user's infomation (i.e., location).

    NOTE: This module is a very simple version of dns server, called global load ba-
          lance dns server. We suppose that this server knows all the ip addresses of 
          cache servers for any given domain_name (or cname).
    """
    
    def __init__(self, request, client_address, server):
        self.table = server.table
        super().__init__(request, client_address, server)

    def calc_distance(self, pointA, pointB):
        ''' TODO: calculate distance between two points '''
        ...

    def get_response(self, request_domain_name):
        response_type, response_val = None, None
        # ------------------------------------------------
        # TODO: your codes here.
        # Determine an IP to response according to the client's IP address.
        #       set "response_ip" to "the best IP address".
        client_ip, _ = self.client_address
        entry = None
        for cur_entry in self.table:
            name1 = request_domain_name
            name2 = cur_entry.domain_name
            if name1[-1] == '.':
                name1 = name1[:len(name1) - 1]
            if name2[-1] == '.':
                name2 = name2[:len(name2) - 1]
            #print(name1, name2)
            if fnmatch.fnmatch(name1, name2):
                entry = cur_entry
                #print(entry.domain_name, entry.record_type, entry.record_values)
                break
        if entry == None: # 未匹配到表项
            pass
        else:
            index = 0
            if entry.record_type == 'CNAME': # 类型为CNAME
                pass
            else: # 类型为A
                if len(entry.record_values) == 1: # 长度为1
                    pass
                else: # 长度大于1
                    client_x, client_y = IP_Utils.getIpLocation(client_ip)
                    if client_x is None or client_y is None:
                        index = randint(0, len(entry.record_values) - 1)
                    else:
                        entry_x, entry_y = IP_Utils.getIpLocation(entry.record_values[0])
                        for i in range(len(entry.record_values)):
                            cur_entry_x, cur_entry_y = IP_Utils.getIpLocation(entry.record_values[i])
                            if cur_entry_x is None or cur_entry_y is None:
                                continue 
                            if (entry_x is None or entry_y is None) or math.fabs(cur_entry_x - client_x) ** 2 + math.fabs(cur_entry_y - client_y) ** 2 <  math.fabs(entry_x - client_x) ** 2 + math.fabs(entry_y - client_y) ** 2:
                                index = i
            response_type = entry.record_type
            response_val = entry.record_values[index]

        # -------------------------------------------------
        return response_type, response_val

    def handle(self):
        """
        This function is called once there is a dns request.
        """
        ## init udp data and socket.
        udp_data, socket = self.request

        ## read client-side ip address and udp port.
        client_ip, client_port = self.client_address

        ## check dns format.
        valid = DNS_Request.check_valid_format(udp_data)
        if valid:
            ## decode request into dns object and read domain_name property.
            dns_request = DNS_Request(udp_data)
            request_domain_name = str(dns_request.domain_name)
            self.log_info(f"Receving DNS request from '{client_ip}' asking for "
                          f"'{request_domain_name}'")

            # get caching server address
            response = self.get_response(request_domain_name)

            # response to client with response_ip
            if None not in response:
                dns_response = dns_request.generate_response(response)
            else:
                dns_response = DNS_Request.generate_error_response(
                                             error_code=DNS_Rcode.NXDomain)
        else:
            self.log_error(f"Receiving invalid dns request from "
                           f"'{client_ip}:{client_port}'")
            dns_response = DNS_Request.generate_error_response(
                                         error_code=DNS_Rcode.FormErr)

        socket.sendto(dns_response.raw_data, self.client_address)

    def log_info(self, msg):
        self._logMsg("Info", msg)

    def log_error(self, msg):
        self._logMsg("Error", msg)

    def log_warning(self, msg):
        self._logMsg("Warning", msg)

    def _logMsg(self, info, msg):
        ''' Log an arbitrary message.
        Used by log_info, log_warning, log_error.
        '''
        info = f"[{info}]"
        now = datetime.now().strftime("%Y/%m/%d-%H:%M:%S")
        sys.stdout.write(f"{now}| {info} {msg}\n")
