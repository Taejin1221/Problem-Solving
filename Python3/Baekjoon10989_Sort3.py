# Baekjoon10989_Sort3.py
import sys
input = sys.stdin.readline

n = int( input() )
counts = [ 0 ] * 10001

for _ in range( n ):
	num = int( input() )
	counts[num] += 1

for i, num in enumerate( counts ):
	for _ in range( num ):
		print( i )
