
# Experiment : 2
# list as a container

mylist = [10, 'A', '123']

# Print all the elements of list
print "--> Printing all the elements in the list"
print " "*10,; print mylist		

# Print element by element
print "--> Printing element by element using for loop"; print " "*10,
for ele in mylist:
	print ele,		
print

# Print element by element
print "--> Printing element by element using while loop"; print " "*10,
i = 0
while (i < len(mylist)):
	print mylist[i],
	i += 1
print

# Printing number of elements in the list
print "--> Number of elements in the list : %d" %(len(mylist))

# Insert an element at the beginning
print "--> Inserting 'Hello' at the beginning"
mylist.insert(0, "Hello")
print " "*10,; print mylist			# Print elements after inserting

# Insert an element at the position 1
print "--> Inserting '25' at the position 1"
mylist.insert(2, 25)
print " "*10,; print mylist			# Print elements after inserting

# Insert an element at the end
print "--> Inserting '143' at the end"
mylist.append(143)
print " "*10,; print mylist			# Print elements after inserting

# Delete element at position 1
print "--> Deleting at position 1"
mylist.pop(1)
print " "*10,; print mylist			# Print elements after deleting

# Delete element at position 1 and printing it
ele = mylist.pop(1)
print "--> List after deleting at position 1"
print " "*10,; print mylist			# Print elements after deleting
print " "*10,; print "Deleted element is : %d" %ele

# Delete element by value
print "--> List after deleting 'Hello'"
mylist.remove('Hello')
print " "*10,; print mylist			# Print elements after deleting
