
# Module with functions for scientific calculator

import math

# sine
def sine(angle):
	'''sine(x) -> value

Return the sine of x in radians.'''

	return math.sin(angle)

# cosine
def cosine(angle):
	'''cosine(x) -> value

Return the cosine of x in radians.'''

	return math.cos(angle)

# square root
def square_rt(num1):
	'''squre_rt(x) -> value

Return the square root of x.'''

	return math.sqrt(num1)

# power
def power(num, pwr):
	'''power(x, y) -> value

Return the value of x raised to the power of y.'''

	return pow(num, pwr)
