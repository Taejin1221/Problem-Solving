# Baekjoon01157_WordStudy.py
alphabets = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
cntAlphabet = { a : 0 for a in alphabets }

word = input()
word = word.upper()
for char in word:
	cntAlphabet[char] += 1

sortedAlphabet = sorted( cntAlphabet.items(),
	key = lambda item : item[1], reverse = True )

if ( sortedAlphabet[0][1] == sortedAlphabet[1][1] ):
	print( '?' )
else:
	print( sortedAlphabet[0][0] )