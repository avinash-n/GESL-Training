
# Exception handling

# Handling the exception raised
if (0):
	try:
		a = 10 / input()
	except ZeroDivisionError, detail:
		print "Divide by zero attempted"; print detail
		try:
			x = 10
			print "x = ", x
			print a
		except NameError, detail:
			print "Undefined variable name"; print detail
	else:
		print "a = ", a
	finally:
		print "Exception handler"

# Raising the exception and handling it
elif (1):
	try:
		print "Hello"
		x = raise TypeError
#		raise TypeError
#		raise SyntaxError
#		raise AttributeError
	except SyntaxError, msg1:
		print "Invalid syntax"; print msg1
	except TypeError, msg2:
		print "Type error occured"; print msg2
	except AttributeError, msg3:
		print "Attribute error occured"; print msg3
	except NameError, detail:
		print "Name error occured"; print detail
	else:
		print "'raise <error>' failed"
	finally:
		print "Exception generator"
