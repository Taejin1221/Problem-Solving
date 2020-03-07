# Baekjoon18258_Queue2.py
import sys
input = sys.stdin.readline

q = []
front, size = 0, 0
for _ in range( int( input() ) ):
	inst = input().rstrip().split()

	if inst[0] == 'push':
		q.append( int( inst[1] ) )
		size += 1

	elif inst[0] == 'pop':
		if size:
			print( q[front] )
			front += 1
			size -= 1
		else:
			print( -1 )

	elif inst[0] == 'size':
		print( size )

	elif inst[0] == 'empty':
		if size:
			print( 0 )
		else:
			print( 1 )

	elif inst[0] == 'front':
		if size:
			print( q[front] )
		else:
			print( -1 )
		
	elif inst[0] == 'back':
		if size:
			print( q[-1] )
		else:
			print( -1 )
