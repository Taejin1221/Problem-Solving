# Baekjoon05430_AC.py
import sys
input = sys.stdin.readline

for _ in range( int( input() ) ):
	inst = input().rstrip()
	n = int( input() )
	nums = input().rstrip()[1:-1].split( ',' )

	front, rear, plus = 0, (n - 1), 1
	for i in inst:
		if i == 'R':
			plus *= -1
			front, rear = rear, front
		else:
			size = (rear - front) if plus > 0 else (front - rear)
			if size > -1 and nums[front]:
				front += plus
			else:
				print( 'error' )
				break
	else:
		printNums = [ ]
		for idx in range( front, rear + plus, plus ):
			printNums.append( nums[idx] )
		print( '[' + ','.join( printNums ) + ']' )
