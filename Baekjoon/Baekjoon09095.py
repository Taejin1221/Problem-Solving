# Baekjoon09095_Add123.py
# https://www.acmicpc.net/problem/9095
import sys

def backtracking( prevSum ):
	global count
	if prevSum == n:
		count += 1
	elif prevSum < n:
		backtracking( prevSum + 1 )
		backtracking( prevSum + 2 )
		backtracking( prevSum + 3 )

for _ in range( int( sys.stdin.readline() ) ):
	n = int( sys.stdin.readline() )

	count = 0
	backtracking( 0 )

	print( count )

	# O(1) Solution
	answers = [ 0, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274 ]
	print( answers[n] )
