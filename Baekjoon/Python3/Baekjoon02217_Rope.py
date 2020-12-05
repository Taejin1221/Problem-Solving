# Baekjoon02217_Rope.py
# https://www.acmicpc.net/problem/2217
import sys
input = sys.stdin.readline

n = int( input() )

weights = [ ]
for _ in range( n ):
	weights.append( int( input() ) )

weights.sort()

maxWeights = 0
for i in range( n ):
	maxWeights = max( maxWeights, weights[i] * ( n - i ) )

print( maxWeights )
