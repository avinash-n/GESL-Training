'''
import time, datetime
import socket
from pyicmp import messages
from pyicmp import ip as ip_m

icmp = socket.getprotobyname('icmp')

class Ping:
	
	def __init__(self, ip, port, identifier, sequence, ttl, timeout = 5, repeat = 4, sleep = 0.25):
		#init result
		self.result = {
			'ip' : ip,
			'on' : False,
			'hostname' : None,
			'times' : [],
			'mdev' : 0,
			'avg_time' : 0,
			'packet_loss' : 0,
			'ttl': ttl,
			'responses' : []
		}
		#do pings
		for x in range(0, repeat):
			self.one_ping(ip, port, identifier, sequence, ttl, timeout)
			sequence += 1
			if x != repeat -1:
				time.sleep(sleep)
		#count packet loss
		self.result['packet_loss'] /= repeat
		#try to get hostname
		try:
			self.result['hostname'] = socket.gethostbyaddr(ip)[0]
		except socket.herror:
			self.result['hostname'] = None
		#calculate averate time
		if len(self.result['times']) != 0:
			self.result['avg_time'] = sum(self.result['times']) / len(self.result['times'])
			#and calculate mdev
			mean = sum([float(x) for x in self.result['times']]) / len(self.result['times'])
			self.result['mdev'] = sum([abs(x - mean) for x in self.result['times']]) / len(self.result['times'])

	
	def one_ping(self, ip, port, identifier, sequence, ttl, timeout):
		#prepare result dict
		result = {'error': None}
		
		#create sockets
		ins = socket.socket(socket.AF_INET, socket.SOCK_RAW, icmp)
		outs = socket.socket(socket.AF_INET, socket.SOCK_RAW, icmp)
		#bind and set timeout for IN socket
		ins.bind(("", port))
		ins.settimeout(timeout)
		#set TTL for OUT socket
		outs.setsockopt(socket.SOL_IP, socket.IP_TTL, ttl)
		
		#create packet and send it
		#print('sending to', ip, 'packet with', identifier, sequence)
		packet = messages.EchoRequest(identifier = identifier, sequence = sequence)
		outs.sendto(packet.pack(), (ip, port))
		
		#get answer and time it
		start = datetime.datetime.now()
		try:
			s = time.time()
			while time.time() - s < timeout:
				a  = ins.recvfrom(1024)[0]
				ip_header = ip_m.Header(a[:20])
				outp = messages.types[a[20]]()
				outp.unpack(a[20:])
				#print('received from', ip, 'packet', type(outp), 'with', outp.identifier, outp.sequence, 'policy:', type(outp) in messages.reply_messages and identifier == outp.identifier and sequence == outp.sequence, 'result so far:', result)
				if (
					(
						#handle errors
						type(outp) in messages.error_messages and
						#cover not specification complient routers
						outp.original_message is not None and
						identifier == outp.original_message.identifier and
						sequence == outp.original_message.sequence
					)
					or
					(
						#handle normal responses
						type(outp) in messages.reply_messages and
						identifier == outp.identifier and
						sequence == outp.sequence
					)
				):
					if type(outp) == messages.EchoReply:
						self.result['on'] = True
					delta = datetime.datetime.now() - start
					self.result['times'].append(delta.seconds * 1000000 + delta.microseconds)
					self.result['responses'].append((ip_header, outp))
					break
		except socket.timeout as e:
			self.result['packet_loss'] += 1
'''

from struct import pack, unpack
import socket
from random import random
from time import sleep, time
import sys
ICMP_ECHO = 8
FP = 1

class ICMPImplementation():
    def __init__(self):
        self.proto = socket.getprotobyname("icmp")
        self.socketObj = self.socketHandler()
        
    def socketHandler(self):
        try:
            return socket.socket(socket.AF_INET, socket.SOCK_RAW, self.proto)
        except socket.error as e:
            id,msg = e.args
            print "Error: socket creation failed \n Desc: {}".format(msg) 
            sys.exit()
        
    def packet(self,IDENTITY):
        pktHeader = pack("bbHHh", ICMP_ECHO, 0, 0, IDENTITY, 1)
        pktData = 100 * 'WC'
        pkt = pktHeader + pktData
        checksum = 0
        limit = len(pkt) & -2
        count = 0
        while count < limit:
            chunk = ord(pkt[count + 1]) * 256 + ord(pkt[count])
            checksum += chunk
            checksum &= 0xffffffff  
            count += 2
        if limit < len(pkt):
            checksum += ord(pkt[len(pkt) - 1])
            checksum &= 0xffffffff  
        checksum = (checksum >> 16) + (checksum & 0xffff)
        checksum += checksum >> 16
        answer = ~checksum
        answer &= 0xffff
        pktHeader = pack("bbHHh", ICMP_ECHO, 0, socket.htons(answer >> 8 | (answer << 8 & 0xff00)), IDENTITY, 1)
        return pktHeader + pktData
    
    def ping(self, dstAddr, timeout, pktCount):
        try:
            dstAddr = socket.gethostbyname(dstAddr)
        except:
            print "Error: invalid host address, must be an url(google.com) or proper IP address"
            sys.exit()
        pkt = self.packet(int((id(timeout) * random()) % 65535))
        timestamp = time()
        print "*************************************************"
        print "************ RAW ICMP IMPLEMENTATION ************"
        print "*************************************************"
        print "\n"
        print "Pinging {}, Total Packets: {} Timeout: {}, Unix_Timestamp: {}".format(dstAddr, pktCount, timeout, timestamp)
        for liter in range(0,pktCount):
            delay = time()*1000
            self.socketObj.sendto(pkt, (dstAddr, 1))
            resp, addr= self.socketObj.recvfrom(1024)
            icmp_header = resp[20:28]
            type, code, checksum, rec_id, sequence = unpack("bbHHh", icmp_header)
            if type == 8 or type == 0:
                print "Echo from: {}, ping successfull, time_delay: {} ms".format(dstAddr,time()*1000 - delay)
                sleep(FP)
            elif type == 3:
                if code == 0:
                    des = "net unreachable"
                elif code == 1:
                    des = "host unreachable"
                elif code == 1:
                    des = "protocol unreachable"
                elif code == 1:
                    des = "port unreachable"
                elif code == 1:
                    des = "fragmentation needed and DF set"
                elif code == 1:
                    des = "source route failed"
                else:
                    des = "cause of failure unknown"
                print "Ping failed: Timeout, {}".format(des)
   
if __name__ == "__main__":
    dstHostAddr = '172.16.5.25'
    timeout = 1
    pktCount = 5
    ICMPImplementation.ping(ICMPImplementation(), dstHostAddr,timeout,pktCount)
