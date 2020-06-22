# Baekjoon02675_RepeatString.py
import sys

input = sys.stdin.readline

time = int( input() )

for _ in range( time ) :
	R, S = input().split()
	R = int( R )

	P = ''
	for s in S:
		P = P + s * R

	print( P )