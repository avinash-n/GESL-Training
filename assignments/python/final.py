import os

print "Tic Tac Toe".center(50,'-')

l = [['_','_','_'],['_','_','_'],['_','_','_']]

def show(l) :
	os.system("clear")
	for i in range(0,3) :
		for j in range(0,3) :
			print l[i][j],"   ",
		print "\n"
def base() :
	print "provided numbers for provided positions"
	num = 0
	for i in range (0,3) :
		for j in range(0,3) :
			print num,"   ",
			num += 1
		print "\n"

count = 1
while count<=9 :
	count += 1
	show(l)
	base()
	print "Its player 1's turn"
	pos = input("Enter required position you want to place")
	i = pos/3
	j = pos%3
	while l[i][j] != '_' :
		print "Its already filled"
		pos = input("Enter required position you want to place")
		i = pos/3
		j = pos%3
	l[i][j] = 1
	check = 0
	for t in range(0,3) :
		if l[t][j] == 1 :
			check+=1
	if check == 3 :
		show(l)
		print "player 1 won"
		exit()
	check = 0
	for t in range(0,3) :
		if l[i][t] == 1 :
			check+=1
	if check == 3 :
		show(l)
		print "player 1 won "
		exit()
	
	if i-j == 1 or j-i == 1 :
		pass
	else :
		if (i == j) or (i == 1 and j == 1 ) :
			check = 0
			for t in range(0,3) :
				if l[t][t] == 1 :
					check+=1
			if check == 3 :
				show(l)
				print "player 1 won"
				exit()
		if ( i == 1 and j == 1 ) or  (i == 0 and j==2) or (j == 0  and i == 2) :
			check = 0
			for t in range(0,3) :
				if l[t][2-t] == 1 :
					check += 1
			if check == 3 :
				show(l)
				print "player 1 won"
				exit()
	if count >= 9 :
		break
	count += 1
	show(l)
	print "Its player 2's turn"
	base()
	pos = input("Enter the required position you want to place")
	i = pos/3
	j = pos%3
	while l[i][j] != '_' :
		print "Its already filled"
		pos = input("Enter required position you want to place")
		i = pos/3
		j = pos%3
	l[i][j] = 0
	check = 0
	for t in range(0,3) :
		if l[t][j] == 0 :
			check += 1
	if check == 3 :
		show(l)
		print "Player 2 won"
		exit()
	check = 0
	for t in range(0,3) :
		if l[i][t] == 0 :
			check += 1
	if check == 3 :
		show(l)
		print "player 2 won "
		exit()
	if i-j == 1 or j-i == 1 :
		pass
	else :
		if (i == j) or (i == 1 and j == 1 ) :
			check = 0
			for t in range(0,3) :
				if l[t][t] == 0 :
					check += 1
			if check == 3 :
				show(l)
				print "player 2 won"
				exit()
		if ( i == 1 and j == 1 ) or ( (i == 0 and j==2) or (j == 0 and i==2 )) :
			check = 0
			for t in range(0,3) :
				if l[t][2-t] == 0 :
					check += 1
			if check == 3 :
				show(l)
				print "player 2 won"
				exit() 
show(l)
print "Match draw"
