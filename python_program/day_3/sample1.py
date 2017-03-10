#! /usr/bin/python

import sys
import os

# Implementation of cat command

if (0):
	if (len(sys.argv) == 2):
		if (os.path.isfile(sys.argv[1])):
			print "'cat' is working"
			f1 = open(sys.argv[1], "r")
			print "Contents of file %r :" %(sys.argv[1])
			sys.stdout.write(f1.read())
			f1.close()
		else:
			print "File %r doesn't exist" %(sys.argv[1])
	elif (len(sys.argv) < 2):
		print "Too few parameters (expects 2)"
	else:
		print "Too many parameters (expects 2)"

# Implementation of cp command

elif (0):
	if (len(sys.argv) == 3):
		if (os.path.isfile(sys.argv[1])):
			print "'cp' is working"
			f1 = open(sys.argv[1], "r")
			f2 = open(sys.argv[2], "w")
			f2.write(f1.read())
			f1.close()
			f2.close()
			print "Contents of %r is copied into %r" %(sys.argv[1], sys.argv[2])
		else:
			print "File %r doesn't exist" %(sys.argv[1])
	elif (len(sys.argv) < 3):
		print "Too few parameters (expects 2)"
	else:
		print "Too many parameters (expects 2)"

# Implementation of wc command

elif (0):
	if (len(sys.argv) == 2):
		if (os.path.isfile(sys.argv[1])):
			print "'wc' is working"
			f1 = open(sys.argv[1], "r")
			count = 0
#			for ele in f1.read():
#				if ((ele == ' ') or (ele == '\n')):
#					count += 1
			f1.close()
			print "Number of words in file %r : %r" %(sys.argv[1], len(f1.read().split()))
		else:
			print "File %r doesn't exist" %(sys.argv[1])
	elif (len(sys.argv) < 2):
		print "Too few parameters (expects 2)"
	else:
		print "Too many parameters (expects 2)"

# Write into and readback from the same file
# Constraint 1 : Without using seek()

elif (0):
	if (len(sys.argv) == 2):
		str1 = "This is the content written into file\n"
		f1 = open(sys.argv[1], "w")
		f1.write(str1)
		f1.close()
		f2 = open(sys.argv[1], "r")
		print f2.read()
		f2.close()
	elif (len(sys.argv) < 2):
		print "Too few parameters (expects 2)"
	else:
		print "Too many parameters (expects 2)"

# Constraint 2 : By using seek()

elif (0):
	if (len(sys.argv) == 2):
		str1 = "This is the content written into file\n"
		f1 = open(sys.argv[1], "w+")
		f1.write(str1)
		f1.seek(0)
		print f1.read()
		f1.close()
	elif (len(sys.argv) < 2):
		print "Too few parameters (expects 2)"
	else:
		print "Too many parameters (expects 2)"

# Split a string into words and print number words
# Use join() to recreate the string
# Join using ,(comma) as delimitor

elif (1):
	str1 = "Global Edge"
	delim = ','
	print "String : ", str1
	print "Number of words : ", len(str1.split())
	print "Words : ", str1.split()
	print "String after joining with ','(comma) as delimitor: ", delim.join(str1.split())
