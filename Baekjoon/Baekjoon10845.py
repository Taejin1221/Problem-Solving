# Baekjoon10845_Queue2.py
import sys
input = sys.stdin.readline

queue = []
for _ in range( int( input() ) ):
	inst = input().rstrip().split()

	if inst[0] == 'push':
		queue.append( int( inst[1] ) )
	elif inst[0] == 'pop':
		if queue:
			print( queue.pop(0) )
		else:
			print( -1 )
	elif inst[0] == 'size':
		print( len( queue ) )
	elif inst[0] == 'empty':
		if queue:
			print( 0 )
		else:
			print( 1 )
	elif inst[0] == 'front':
		if queue:
			print( queue[0] )
		else:
			print( -1 )
	elif inst[0] == 'back':
		if queue:
			print( queue[-1] )
		else:
			print( -1 )
