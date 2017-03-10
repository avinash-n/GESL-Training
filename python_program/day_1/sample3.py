
# Experiment : 3

# Program for fibonacci series

mylist = []
mylist.append(1)
mylist.append(1)

print "1. Input number of elements\n2. Input range"
opt = input("Enter your choice: ")

if (opt == 1):
	num = input("Enter the number of elements of fibonacci series to be printed: ")
	print mylist[0], mylist[1],
	i = 2
	while (num > 2):
		num -= 1
		mylist.append(mylist[i - 1] + mylist[i - 2])
		print mylist[i],
		i += 1

elif (opt == 2):
	limit = input("Enter the range upto which fibonacci series is to be printed: ")
	print mylist[0], mylist[1],
	i = 2
	mylist.append(mylist[i - 1] + mylist[i - 2])
	while (mylist[i] < limit):
		print mylist[i],
		i += 1
		mylist.append(mylist[i - 1] + mylist[i - 2])
else:
	print "Invalid input"

print
