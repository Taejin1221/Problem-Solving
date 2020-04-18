# Baekjoon01874_StackSequence.py
import sys

n = sys.stdin.readline()

rtrn = [ ]
stck, curr = [ ], 1
for num in map( int, sys.stdin ):
	if num > curr:
		while curr <= num:
			stck.append( curr )
			rtrn.append( '+' )
			curr += 1

		stck.pop()
		rtrn.append( '-' )
	elif num < curr:
		if stck[-1] != num:
			print( 'NO' )
			break
		else:
			stck.pop()
			rtrn.append( '-' )
	else:
		curr += 1
		rtrn.append( '+' )
		rtrn.append( '-' )
else:
	for s in rtrn:
		print( s )
