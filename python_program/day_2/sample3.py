def fun1():
	'''Simple function'''
	print "This is function 1"
fun1()

def fun2_1():
	'''Function returning a string but no output'''
	print "This is function 2 with no output"
	return "This is function 2 with no output"
fun2_1()

def fun2_2():
	'''Function returning a string with output'''
	return "This is function 2 with output"
x = fun2_2()
print x

def fun3(a, b):
	'''Function with actual values as parameters'''
	print "This is function 3 :", 
	print a, b
fun3(10, 20)

x = 30; y = 40
def fun4(a, b):
	'''Function with variables as parameters'''
	print "This is function 4 :", 
	print a, b
fun4(x, y)

def fun5(a, b):
	'''Function with initialized variables as parameters'''
	print "This is function 5 :", 
	print a, b
fun5(a = 50, b = 60)

def fun6(a, b):
	'''Function with initialized variables as parameters \
but not in order'''
	print "This is function 6 :", 
	print a, b
fun6(b = 70, a = 80)

def fun7(a = 10, b = 20):
	'''Function with partially initialized variables as parameters \
an with default values for arguments'''
	print "This is function 7 :", 
	print a, b
fun7(b = 90)

#def fun8(a = 10, b):
#print "This is function 8 :", 
#print a, b
#fun8(b = 90)

def fun9(a, b = 10):
	'''Function with initialized variables as parameters'''
	print "This is function 9 :", 
	print a, b
fun9(110, b = 100)

print "This is function 10 :", 
print x,
def fun10():
	print x,
fun10()
print x

x = 100
print "This is function 11 :", 
print x,
def fun11():
	x = 200		# Local
	print x,
fun11()
print x

x = 100
print "This is function 12 :", 
print x,
def fun12():
	global x
	x = 200		# Global
	print x,
fun12()
print x
