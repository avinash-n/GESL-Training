'''question 3'''
if (0):
	l = ['Monty','Python'] * 20
	num = input ("enter the number:")
	l = ['Monty','Python'] * 3 * num
#----------------------------------------------------------------------------
'''question 4'''
if (0):
	text4 = {1,2,3,45}
	print  len(set(text4))
#----------------------------------------------------------------------------
'''question 5'''
if(0):
	my_string = "hiii gud evening"
	print my_string + my_string
	print my_string * 3
	print my_string+' '+my_string
#-----------------------------------------------------------------------------	
'''question 6'''
if(0):
	mysent = ['heloo','gud','evening']
	a = ' '.join(mysent)
	print a
	b = a.split(' ')
#-----------------------------------------------------------------------------
'''question 7'''
if(0):
	text1 = "hello everyone"
	text2 = "gud evening"
	
	print len(text1+text2)
	print len(text1)+len(text2)
#-----------------------------------------------------------------------------	
'''question 8'''
if(0):
	text1 = "welcomE"
	text2 = "globaledge"
	sorted(set([text1.lower() for e in text1]))
	sorted([text1.lower() for e in set(text1)])	
#---------------------------------------------------------------------
'''question 9'''
if(0):
	w = "case checking"
	w.isupper()
	not w.islower()
#---------------------------------------------------------------------
'''question 10'''
if (0):
	text2 = "hi mams gud morning and welcome"
	x = text2.split()
	x[-2:]
#----------------------------------------------------------------------
'''question 11'''
if(0):
	Sent = ['she', 'sells', 'sea', 'shells', 'by', 'the', 'sea', 'shore']

	for words in Sent:

		if words.startswith ('sh'):

			print words 
	
		
	for words in Sent:

		if len (words)> 4:

			print words 
#----------------------------------------------------------------------
'''question 12'''
if(0):
	text = "size prize pt path zebra"
	text6 = text.split()
	Speclist = []

	for eachword in text6:

		if eachword.endswith ('ize'):
			Speclist.append (eachword)
			
	print Speclist

	for eachword in text6:

		if 'z' in eachword:

			Speclist.append (eachword)
	print Speclist

'''
C. Only change the sentence if 'pt' in eachword , the other same
	if eachword.istitle (): 
'''
#----------------------------------------------------------------------
'''question 13'''
if(0):
	text1 = "what is this and why"
	sum([len(w)for w in text])
	average = sum([len(w)for w in text]) / len(text1)
	print average
#----------------------------------------------------------------------
'''question 14'''
if(0):
	def vocab_size(text):
		count = 0
		text = text.split()
#		return len(text.split())
		for word in text:
			count += len(word)
		return count

	text = raw_input("enter the text:")
	print vocab_size(text)
#----------------------------------------------------------------------
'''question 15'''
if(0):
	def fun_percent(word,text):
		a = len(text.split())
		print a
		b = text.count(word)
		print b
		return ((float(b)/float(a)) * 100)
	
	text = raw_input ("enter the text")
	word = raw_input ("enter the word")
	print fun_percent(word,text)
#-----------------------------------------------------------------------------
'''question 16'''
if(1):
	text1 = "hiiii everyone"
	text2 = "hiiii everyone gud evening"
	x = set(text1) < set(text2)
	print x
'''checks whaether text1 is subset of text2 or not anhd returns boolean'''
#-----------------------------------------------------------------------------
'''question 17'''
if(0):
	s  = 'colorless'
	a = s[0:4]
	b = s[4:]
	print a + 'u' + b
#----------------------------------------------------------------------
'''question 18'''
if(0):
	word = raw_input("enter the word")
	n = word.index('-')
	word  = word[0:n] + word[(n+1):]
	print word
	
#----------------------------------------------------------------------
'''question 19'''
#---------------------------------------------------------------------------
'''question 20'''
if(0):
	import urllib
	import sys
	from bs4 import BeautifulSoup

	f1 = urllib.urlopen(sys.argv[1]) 
	html = f1.read()

	soup = BeautifulSoup(html,"lxml")

	for script in soup(["script","style"]):
		script.extract()

	text = soup.get_text()

	lines = (line.strip() for line in text.splitlines())
	chunks = (phrase.strip() for line in lines for phrase in line.split("  "))
	text = '\n'.join(chunk for chunk in chunks if chunk)

	print text.encode("utf-8")
#----------------------------------------------------------------------
'''question21'''
if(0):
	words = ["venkat","saaquib","shweta","preethi"]
	print words.sort()
	print sorted(words)
#---------------------------------------------------------------------------
'''question 22'''
if(0):
#	from test import msg
	import test
	
	print test.msg
#-----------------------------------------------------------------------------
'''question 23'''
if(0):
	import webbrowser
	url = raw_input("enter the url:")
	webbrowser.open(url)
#-----------------------------------------------------------------------------
