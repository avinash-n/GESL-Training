
if (0):
# Use of common attribute in a class(class bound datamembers, static)
	class Emp():
		count = 0					# Count can be accessed from any methods inside the class
		def __init__(self, x):
			Emp.count += 1			# .count is accessible and shared by all objects of class
			self.sal = x			# .sal is specific to each newly created object of class
		def disp(self):
			return Emp.count, self.sal
		def __del__(self):
			pass

	emp1 = Emp(10000)
	print "Count is class bound"
	print "*"
	print emp1.disp()
	print (emp1.count, emp1.sal)
	emp2 = Emp(15000)
	print "*"
	print emp2.disp()
	print (emp2.count, emp2.sal)
	print "*"
	print emp1.disp()
	print (emp1.count, emp1.sal)
# Note : count is being shared ie., updated with each object creation and invoking

elif (0):
# Use of common attribute in a class(class bound datamember, local)
	class Emp():
		count = 0					# Count can be accessed from any methods inside the class
		def __init__(self, x):
			self.count += 10		# .count is accessible seperately by each object of class
			self.sal = x			# .sal is specific to each newly created object of class
		def disp(self):
			return self.count, self.sal
		def __del__(self):
			pass

	emp1 = Emp(10000)
	print "Count is object bound"
	print "*"
	print emp1.disp()
	print (emp1.count, emp1.sal)
	emp2 = Emp(15000)
	print "*"
	print emp2.disp()
	print (emp2.count, emp2.sal)
	print "*"
	print emp1.disp()
	print (emp1.count, emp1.sal)
# Note : count is being created with each object creation and invoking, no updation

elif (1):
# operator overloading
	class Num():
		def __init__(self, start):
			self.data = start
		def __sub__(self, other):
			return Num(self.data - other)
		def disp(self):
			return self.data
	X = Num(7)
	print "x = ", X.disp()
	Y = X - 4
	print "Y = ", Y.disp()
