# Baekjoon09461_WaveSequence.py
# https://acmicpc.net/problem/9461
import sys

time = int( sys.stdin.readline() )
nums = [ ]
for _ in range( time ):
	nums.append( int( sys.stdin.readline() ) )

n = max( nums )

sequence = [ 0, 1, 1, 1, 2, 2 ]

for i in range( 6, n + 1 ):
	sequence.append( sequence[i - 1] + sequence[i - 5] )

for num in nums:
	print( sequence[num] )
