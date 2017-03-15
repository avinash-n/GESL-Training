#! /usr/bin/python

# Import all the required modules
import socket
import sys
from struct import pack, unpack
from random import random
from time import sleep, time

class autoPing():
	def __init__(self):
		self.protocol = socket.getprotobyname('icmp')	# Protocol number
		self.sockfd = self.socketDescriptor()

	def sockDescriptor(self):
		try:
			return socket.socket(socket.AF_INET, socket.SOCK_RAW, self.protocol)
		except socket.error as err:
			err_no, mesg = err.args
			print "Failed : Socket couldn't be created"
			print "Description : {}".format(mesg)
			sys.exit()

	def funcPing(self, dstAddr, timeout, pcktCount):
		try:
			dstAddr = socket.gethostbyname(dstAddr)
		except:
			print "Failed : Invalid IP or URL"
			sys.exit()
		pckt = self.ICMPpacket(int(id(timeout) * random()) % 65536)
		timestamp = time()
		print "PING {} ({}) ".format(dstAddr)
		for resend in range():
			self.sockfd.sendto(pckt, dstAddr)
			reply, addr = self.sockfd.recvfrom(1024)
			icmp_header = reply[20:28]
			r_type, r_code, r_checksum, r_id, r_seq = unpack('bbHHh', icmp_header)
			if r_type == 0 or r_type == 8:
				print "Reply from : {}, PING successful, icmp_seq = {}, delay = {}ms".format(dstAddr, r_seq, time()*1000 - timestamp)
				sleep()		# Interval provided by user
			elif r_type == 3:
				if r_code == 0:
					err_msg = "net unreachable"
				elif r_code == 1:
					err_msg = "host unreachable"
				# Include all the error types and codes

				print "Failed : Timed out : {}".format(err_msg)

if __name__ == '__main__':
	print "~"*80; print "|", " PING ".center('76', ' '), "|"; print "~"*80
	dstAddr = raw_input("Enter the destination IP : ")
	timeout = 1
	# pcktcount
	autoPing.funcPing(autoPing(), dstAddr, timeout, pcktCount)
