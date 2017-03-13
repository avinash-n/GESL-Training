
# Class in python
if (1):
	class A:                                                                        
		def __init__(self):                                                         
			print "In __init__ function "                                           
			self.x = 10	
			self._y = 20
			self.__z = 30
		def fn1(self):
			print self.__z
			print "In fn1 function"
		def _fn2(self):
			self.__fn3()
			print "In _fn2 function"
		def __fn3(self):
			print "In __fn3 function"
		def __del__(self):
			print "In __del__ function "                                           
	m = A()			# A.__init__(m)
	print m.x
	print m._y	
#	print m.__z	
	m.fn1()		
	m._fn2()	
	del (m)
#	m.__fn3()

elif (0):
	x = 10
	print x
	del (x)
	print x
