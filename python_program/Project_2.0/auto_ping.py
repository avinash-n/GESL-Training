#!/usr/bin/python

# Utility for automated pinging
'''Pings the remote host periodically by taking destination host IP
or URL and time interval between each pinging as input from user.

This module makes use of ICMP.'''

# Import all the required modules
import socket
import sys
from struct import pack, unpack
from random import random
from time import sleep, time

ICMP_ECHO = 8

class autoPing():
	def __init__(self):
		'''Constructor for class autoPing.'''
		self.protocol = socket.getprotobyname('icmp')	# Protocol number
		self.sockfd = self.sockDescriptor()

	def sockDescriptor(self):
		'''Create and return socket descriptor through which ICMP
 packets are transmitted.'''
		try:
			return socket.socket(socket.AF_INET, socket.SOCK_RAW, self.protocol)
		except socket.error as err:
			err_no, mesg = err.args
			print "Failed : Socket couldn't be created"
			print "Description : {}".format(mesg)
			sys.exit()

	def ICMPpacket(self, pcktID):
		'''Create and return an ICMP packet.'''
		pcktHeader = pack("bbHHh", ICMP_ECHO, 0, 0, pcktID, 1)
		pcktData = 'PINGDATA' * 25
		pckt = pcktHeader + pcktData
		checksum = 0
		pcktSizeLimit = len(pckt) & -2
		count = 0
		while count < pcktSizeLimit:
			chunk = ord(pckt[count + 1]) * 256 + ord(pckt[count])
			checksum += chunk
			checksum &= 0xffffffff
			count += 2
		if pcktSizeLimit < len(pckt):
			checksum += ord(pckt[len(pckt) - 1])
			checksum &= 0xffffffff
		chechsum = (checksum >> 16) + (checksum & 0xffff)
		checksum += checksum >> 16
		checksum = (~checksum & 0xffff)
		pcktHeader = pack("bbHHh", ICMP_ECHO, 0,\
		socket.htons(checksum >> 8 | (checksum << 8 & 0xff00)), pcktID, 1)
		return pcktHeader + pcktData

	def funcPing(self, dstName, dstAddr, time_int):
		'''Ping the destination host specified by the host name given by user.'''
		pckt = self.ICMPpacket(int((id(time_int) * random()) % (2**16)))
		print "PING {} ({}) getting status".format(dstAddr, dstName)
		global pcktSend
		pcktSend = 0
		global pcktRecv
		pcktRecv = 0

# Looping
		while (pcktSend + 1):
			sendTime = time() * 1000
			try:
				self.sockfd.sendto(pckt, (dstAddr, 1))
				pcktSend += 1
			except:
				print "Unable to resolve destination address '{}' ({})"\
				.format(dstName, dstAddr)
				sys.exit()
	#		try:
			reply, addr = self.sockfd.recvfrom(1024)
			pcktRecv += 1
	#		except:
	#			if (sendTime - (time() * 1000)) > (time_int + 1):
	#				print "Unable to get the response : Timeout"
	#				sys.exit()
			icmp_header = reply[20:28]
			r_type, r_code, r_checksum, r_id, r_seq = unpack("bbHHh", icmp_header)
			if r_type == 8 or r_type == 0:
				print "Reply from : {} ({}), PING successful, icmp_seq = {},\
delay = {}ms".format(dstAddr, dstName, pcktSend, time()*1000 - sendTime)
				sleep(time_int)		# Interval provided by user
			elif r_type == 3:
				if r_code == 0:
					err_msg = "Net Unreachable"
				elif r_code == 1:
					err_msg = "Host Unreachable"
				elif r_code == 2:
					err_msg = "Protocol Unreachable"
				elif r_code == 3:
					err_msg = "Port Unreachable"
				elif r_code == 4:
					err_msg = "Fragmentation Needed and Don't Fragment was Set"
				elif r_code == 5:
					err_msg = "Source Route Failed"
				elif r_code == 6:
					err_msg = "Destination Network Unknown"
				elif r_code == 7:
					err_msg = "Destination Host Unknown"
				# Include all the error types and codes
				else:
					err_msg = "Cause of failure unknown"
				print "Failed : {} : {}".format(dstAddr, err_msg)
				if time_int < 3:
					sleep(time_int)
				else:
					sleep(time_int - 3)		# Interval provided by user

	def __del__(self):
		'''Destructor for class autoPing.'''
		pass

if __name__ == '__main__':
	print "~"*80; print "|", " PING ".center(76, ' '), "|"; print "~"*80
	try:
		def hostName():
			'''Destination IP or URL is taken as input from user'''
			global dstName
			dstName = raw_input("Enter the destination IP or URL : ")
			try:
				global dstAddr
				dstAddr = socket.gethostbyname(dstName)
			except:
				print "Failed : Invalid IP or URL"
				hostName()

		def interval():
			'''Time interval between each pinging is taken as input from user'''
			try:
				global time_int
				time_int = input("Enter the time interval(in seconds) : ")
			except:
				print "Failed : Invalid Input"
				interval()

		hostName()
		interval()
		autoPing.funcPing(autoPing(), dstName, dstAddr, time_int)
	except KeyboardInterrupt:
		print ; print "Forced termination by user"
		print "{} PING status".format(dstName).center(80, '-')
		print "{} Packets transmitted, {} Packets received, {}% Packet loss"\
		.format(pcktSend, pcktRecv, 100 - ((pcktRecv/(pcktSend))*100.0))
		sys.exit()
