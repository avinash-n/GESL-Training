
"""Automated Pinging"""

import os
import time

print " Automated pinging interface ".center(80, '-')
print "1. New PING\n2. STOP ongoing ping"
opt = input("Select the opration : ")

if opt == 1:
# Accept IP from user and time interval to repeat pinging

	hostname = raw_input("Enter the IP address to ping : ")
	interval = input("Enter the time interval(in seconds) for pinging : ")
	while 1:
		response = os.system("ping -c 1 " + hostname)

# Check the response
		if response == 0:
		  print hostname, 'is up and responding!'
		else:
		  print hostname, 'is down and not responding!'
	
		time.sleep(interval)
