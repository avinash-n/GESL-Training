
# Recursion

if (0):
	num = input("Enter the number to find the factorial : ")
	res, temp = 1, 1
	def fact(x):
		if ((x == 0) or (x == 1)):
			return res;
		else:
			res = res * temp
			temp = fact(x-1)
	result = fact(num)
	print "Factorial of %d is %r" %(num, result)

# In python, parameters are passed by object
# Updation of parameter depends on type of object

if (1):
	dct1 = {10:100, "Sachin":200}
	print "Before function call :", dct1
	def dcttest(dct2):
		dct2[10] = 50
		dct2["Sachin"] += 120
		print "Inside function :", dct2
	dcttest(dct2 = dct1)
	print "After function execution :", dct1
