
import math
import sys
import os

# Print binary, hexadecimal and octal equivalent of given number
if (0):
	num = input("Enter a number : ")
	print "Binary equivalent of %d : %r" %(num, bin(num))
	print "Hexadecimal equivalent of %d : %r" %(num, hex(num))
	print "Octal equivalent of %d : %r" %(num, oct(num))

# Print the value of (a) pi
#					 (b) sin(90degree)
elif (0):
	print "Value of pi = %r" %(math.pi)
	print "Value of sin(90) = %d" %(math.sin((math.pi)/2))

# Clear the screen
elif (0):
	print "Clearing the screen"
	os.system('clear')

# Print the current version of python
elif (0):
	print "Version of currently used python is :"
	print sys.version

# Change the working directory
elif (0):
	path = raw_input("Enter the path: ")
	os.chdir(path)
	print os.getcwd()

# Printing prime numbers 
elif (0):
	start = input("Enter the start of range : ")
	end = input("Enter the end of range : ")
	ele = input("Enter the number of elements in the range to be printed : ")

	for num in range(start, end):
		if (ele != 0):
			for i in range(2, num//2):
				if (num % i == 0):
					break
			else:
				print num,
				ele -= 1
	print
