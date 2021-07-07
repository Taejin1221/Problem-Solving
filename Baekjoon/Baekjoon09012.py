# Baekjoon09012_ValidParenthesisString.py
import sys

sys.stdin.readline()

for paren in sys.stdin:
	paren = paren.rstrip()

	stck = [ ]
	for p in paren:
		if p == '(':
			stck.append( 1 )
		else:
			if stck:
				stck.pop()
			else:
				print( 'NO' )
				break
	else:
		if stck:
			print( 'NO' )
		else:
			print( 'YES' )
