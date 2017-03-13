
if (1):
	lst1 = list(range(1, 5))			# Two different ways of creating a list
	lst2 = list([1, 2, 3, 4, 5])		# -do-
	print lst1
	print lst2

	def sqr(x):
		return (x * x)

# Usage of map()
	if (0):
		print map(sqr, lst1)			# Returns a list by evaluating sqr() on it
		print map(lambda x: x * x, lst2)	# Returns a list by evaluating the expression of lambda

# Usage of filter()
	elif (0):
		# Syntax : function(lambda parameter(s): condition, object)
		# Returns a list
		print filter(lambda x: x < 1, lst1)	# Returs a list
		print filter(lambda x: (not(x % 2)), lst2)

# Usage of reduce()
	elif (1):
		# reduce() returns only one value
		str1 = "Hello "
		print reduce(lambda x, y: x + y, lst1)
		print reduce(lambda x, y: x * y, lst1, str1)

# Usage of generator
elif (0):
	# Dynamically generate the list
	print [x**3 for x in range(10) if(1)]


