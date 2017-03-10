
# Experiment : 1
while (1):
	print "-"*25
	# Available code snippets
	print "List of available experiments"
	print "1. Check if the input is equal, greater or less than 100"
	print "2. Print the numbers from 1 to 10"
	print "3. Print the numbers from 1 to 5 using code of experiment 2"
	print "4. Print the numbers from 1 to 10 except 5"
	print "5. Print the message associated with the day of the week entered by the user"
	print "0. Exit"

	opt = input("Select the experiment: ")

	if (opt == 0):
		print "Exiting the program"
		print "-"*25
		break

	elif (opt == 1):
		num1 = input("Enter a number: ")
		if (num1 < 100):
			print "%d is less than 100" %num1
		elif (num1 > 100):
			print "%d is greater than 100" %num1
		else:
			print "Entered value is equal to 100"
		
	elif (opt == 2):
		print "This experiment will print the numbers 1 to 10"
		num2 = 1
		while (num2 <= 10):
			print num2
			num2 += 1

	elif (opt == 3):
		print "This experiment will print the numbers 1 to 5"
		num3 = 1
		while (num3 <= 10):
			if (num3 > 5):
				break
			print num3
			num3 += 1

	elif (opt == 4):
		print "This experiment will print the numbers 1 to 10 except 5"
		num4 = 0
		while (num4 < 10):
			num4 += 1
			if (num4 == 5):
				continue
			print num4

	elif (opt == 5):
		day = raw_input("Enter the day of the week in lower case: ")
		if (day == 'saturday'):
			print "Its saturday, go watch a movie"
		elif (day == 'sunday'):
			print "Its sunday, go to library"
		elif ((day == 'monday') or (day == 'tuesday') or (day == 'wednesday') or (day == 'thursday') or (day == 'friday')):
			print "Its working day, sanku go to office"
		else:
			print "-"*10,; print "Invalid input",; print "-"*10

	else:
		print "Invalid choice"; print "-"*25
