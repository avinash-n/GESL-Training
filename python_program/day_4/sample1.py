
# Class in python

# Illustrating class in python
if (0):
	class A:                                                                        
		def __init__(self):				# Constructor, mandatory                                                         
			print "In __init__ function "                                           
			self.x = 10					# Public, accessible outside class with object                                                                  
			self._y = 20   				# Semi private, accessible outside class with object                                                              
			self.__z = 30  				# Fully private, not accessible outside class directly                                                             
		def fn1(self):					# Public method
#			self.__fn3()				# Fully private method with two underscores
			print "In fn1 function"
		def _fn2(self):					# Semi private method
#			print self.__z				# Fully private method with two underscores
			print "In _fn2 function"
		def __fn3(self):				# Fully private methodi, not accessible outside class directly
			print "In __fn3 function"
		def __del__(self):				# Destructor, optional
			print "In __del__ function "                                           
	m = A()								# A.__init__(m)
	print m.x							# Public attribute with no underscore
	print m._y							# Semi private attribute with one underscore
#	print m.__z							# Fully private attribute with two underscores
	print m._A__z						# Fully private attribute accessed with class name
	m.fn1()								# Public method with no underscore
	m._fn2()							# Semi private method with one underscore
#	m.__fn3()							# Fully private method with two underscores
	m._A__fn3()							# Fully private method accessed with class name
#	fn1(m)								# Cannot be used, NameError

elif (0):
# Base class
	class Shape():
		def __init__(self, x, y):
			self.x = x
			self.y = y
		def area(self):
			return self.x * self.y
		def perimeter(self):
			return (2 * (self.x + self.y))

	myShape = Shape(10, 20)
	print "Area of rectangle = %r" %(myShape.area())
	print "Perimeter of rectangle = %r" %(myShape.perimeter())

# Derived class, from class Shape
	class Square(Shape):
		def __init__(self, x):
			Shape.__init__(self, x, x)
		#	self.x = x
		#	self.y = x

	mySquare = Square(12)
	print "Area of squre = %r" %(mySquare.area())
	print "Perimeter of squre = %r" %(mySquare.perimeter())

# Note : Comment "Shape.__init__(self, x, x)" and uncomment initialization

# Multi-level Derived class, from class Square
	class DoubleSquare(Square):
		def __init__(self, y):
			self.x = y
			self.y = 2*y
		def perimeter(self):
			return ((2 * self.x) + (3 * self.y))

	myDoubleSquare = DoubleSquare(21)
	print "Area of square1 = %r" %(myDoubleSquare.area())
	print "Perimeter of square1 = %r" %(myDoubleSquare.perimeter())

elif (1):
# Mutiple class

	from math import pi

# Base class 1
	class cls1:
		def __init__(self, r):
			self.a = r**2
		def area(self):
			return (pi * self.a)
		def __del__(self):
			pass

# Base class 2
	class cls2:
		def __init__(self, r):
			self.p = r
		def peri(self):
			return (2 * pi * self.p)
		def __del__(self):
			pass

# Derived class
	class Circle(cls1, cls2):
		def __init__(self, r):
			cls1.__init__(self, r)
			cls2.__init__(self, r)
		def __del__(self):
			pass
	try:	
		myCircle = Circle(input("Enter the radius of circle (in cms): "))
		print "Area of circle		: %.2f sqcm" %(myCircle.area())
		print "Perimeter of circle	: %.2r sqcm" %(myCircle.peri())
	except IndentationError, msg:
		print "Improper Indentation"
	except SyntaxError, msg:
		print "Invalid input\nSyntax error occured"
	except TypeError, msg:
		print "Invalid input\nType error occured"
	except NameError, msg:
		print "Invalid input\nName error occured"
