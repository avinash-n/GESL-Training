#exp1 1
#this experiment to comapare the numbers
if(0):
	num=input("Enter a number: ")
	if num>100 : 
		print "num is greater than  100"
	elif num < 100:
		print "num is less than the number"
	else: 
		print "num is equal to 100"

#exp 2
#experiment to print 1 to 100)
elif(0):
	i = 1;
	while(i < 10):
		print(i)
		i = i+ 1

#exp3
#exp t0 print 1 to 0
elif(0):
	while (i < 100):
		if(i < 5):
			print(i)
			i = i+ 1
		else:
			break

#exp4
#to print 1 to 10 except 5
elif(0):
	i = 1
	while(i < 10):
		if( i == 5):
			break
		else:
			print(i)

#exp5
#print days of week
elif(1):
	day = raw_input("enter the week")
	if(day == 'sunday'):
		print("sleep")
	elif(day == 'monday'):
		print("go to office")
	elif(day == 'tuesday'):
		print("go to office")
	elif(day == 'wedday'):
		print("go to office")
	elif(day == 'thursday'):
		print("go to office")
	elif(day == 'friday'):
		print("go to office")
	elif(day == 'saturday'):
		print("sleep")
	else:
		print("enter the correct input")
