
# Calculator program

import os
import basic
import sci

def input_fun():
	'''\nTakes two numbers as input and returns the same.'''
	return input("Enter two numbers :\n"), input()

def simple():
	'''Contains functionalities for simple calculator.'''
	rep1 = 1
	while (rep1 == 1):
		print " Simple Calculator ".center(80, '-')
		print " "*10, "Menu :"
		print " "*15, "1. Addition"
		print " "*15, "2. Subtraction"
		print " "*15, "3. Multiplication"
		print " "*15, "4. Division"
		print " "*15, "5. Back to main menu"
		opt = input("Select operation : ")

		os.system("clear")

		if (opt == 1):
			num1, num2 = input_fun()
			print "Result of addition :\n", "%r + %r = %r" %(num1, num2, basic.add(num1, num2))
			rep1 = 1
		elif (opt == 2):
			num1, num2 = input_fun()
			print "Result of subtraction :\n", "%r - %r = %r" %(num1, num2, basic.sub(num1, num2))
			rep1 = 1
		elif (opt == 3):
			num1, num2 = input_fun()
			print "Result of multiplication :\n", "%r * %r = %r" %(num1, num2, basic.mul(num1, num2))
			rep1 = 1
		elif (opt == 4):
			num1, num2 = input_fun()
			print "Result of division :\n", "%r / %r = %r" %(num1, num2, basic.div(num1, num2))
			rep1 = 1
		elif (opt == 5):
			print "Leaving simple calculator..."
			print "Entering main menu..."
			return 1
		else:
			print "*"*80
			print "  INVALID INPUT  ".center(80, '!')
			print "*"*80

def scientific():
	'''Contains functionalities for scientific calculator.'''
	rep1 = 1
	while (rep1 == 1):
		print " Scientific Calculator ".center(80, '-')
		print " "*10, "Menu :"
		print " "*15, "1. Sine"
		print " "*15, "2. Cosine"
		print " "*15, "3. Square root"
		print " "*15, "4. Power"
		print " "*15, "5. Back to main menu"
		opt = input("Select operation : ")

		os.system("clear")

		if (opt == 1):
			num1 = input("Enter the angle :\n")
			print "Sine of angle (%r) = %r" %(num1, sci.sine(num1))
			rep1 = 1
		elif (opt == 2):
			num1 = input("Enter the angle :\n")
			print "cosine of angle (%r) = %r" %(num1, sci.cosine(num1))
			rep1 = 1
		elif (opt == 3):
			num1 = input("Enter the number :\n")
			print "Square root of (%r) = %r" %(num1, sci.square_rt(num1))
			rep1 = 1
		elif (opt == 4):
			num1 = input("Enter the number :\n")
			num2 = input("Enter the power :\n")
			print "Result of %r to the power %r = %r" %(num1, num2, sci.power(num1, num2))
			rep1 = 1
		elif (opt == 5):
			print "Leaving simple calculator..."
			print "Entering main menu..."
			return 1
		else:
			print "*"*80
			print "  INVALID INPUT  ".center(80, '!')
			print "*"*80

repeat = 1

while (repeat == 1):
#	def calc():
		print " C A L C U L A T O R ".center(80, '-')
		print " "*5, "Main menu :"
		print " "*15, "1. Simple calculator"
		print " "*15, "2. Scientific calculator"
		print " "*15, "3. Exit"
		mode = input("Select the mode : ")
	
		os.system("clear")
	
		if (mode == 1):
#			global repeat
			repeat = simple()
		elif (mode == 2):
#			global repeat
			repeat = scientific()
		elif (mode == 3):
			print "Exiting calculator..."
			break
		else:
			print "*"*80
			print "  INVALID INPUT  ".center(80, '!')
			print "*"*80
		
#calc()
