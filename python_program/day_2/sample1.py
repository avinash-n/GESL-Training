
# Verification of negative indices in containers
if (0):
	print "Negative indices"
	mylist = [10, 20, 30, 40, 50]
	print mylist
	print mylist[-1], mylist[-3], mylist[2]

# Sequences (combination of list and tuple)

# Tuple in a list
elif (0):
	print "Tuple in a list"
	tup_in_lst = [10, 20, (30, 40)]
	print tup_in_lst
	print tup_in_lst[1]
	print tup_in_lst[2]
	print tup_in_lst[2][0]

# List in a tuple
elif (0):
	print "List in a tuple"
	lst_in_tup = (10, 20, [30, 40])
	print lst_in_tup
	print lst_in_tup[0]
	print lst_in_tup[2]
	print lst_in_tup[2][1]

# Slicing
elif (0):
	print "Slicing"
	mylist = [10, 20, 30, 40, 50]
	print mylist
	print mylist[:3]
	print mylist[2:]
	print mylist[:]
	print mylist[::2]

# Dictionary
elif (1):
	print "Dictionary"
	mydict = {308:{54:['Avinash', 'ECE'], 61:['Geetha', 'CSE']}, 309:{12:['Shruthi','ECE']}}
	print mydict[308][61][0]
	print mydict[309][12]
