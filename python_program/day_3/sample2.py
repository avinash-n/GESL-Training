
# Importing package for using the modules in it

# Invoking function w.r.t package
if (0):
	import phone
 
	print "Method I"
	phone.isdn()
	phone.g3()
	phone.pots()

# Invoking function w.r.t module in package
elif (0):
	import phone
 
	print "Method II"
	phone.isdn.isdn()
	phone.g3.g3()
	phone.pots.pots()


# Invoking function w.r.t module
elif (1):
	import phone

	from phone import isdn
	from phone import g3
	from phone import pots

	print "Method III"
	isdn.isdn()
	g3.g3()
	pots.pots()
