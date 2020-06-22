# Baekjoon04949_BalancedWorld.py
import sys

for string in sys.stdin:
	rowString = string.split('.')[0]
	if rowString == '':
		break

	stck = [ ]
	for s in rowString:
		if s == '(':
			stck.append( 0 )
		elif s == '[':
			stck.append( 1 )

		elif s == ')':
			if stck and stck[-1] == 0:
				stck.pop()
			else:
				print( 'no' )
				break

		elif s == ']':
			if stck and stck[-1] == 1:
				stck.pop()
			else:
				print( 'no' )
				break
	else:
		if stck:
			print( 'no' )
		else:
			print( 'yes' )
