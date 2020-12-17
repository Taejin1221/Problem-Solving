# Baekjoon09570_GenerationOfTribbles.py
# https://www.acmicpc.net/problem/9507
import sys
input = sys.stdin.readline

dp = [ 1, 1, 2, 4 ]

for i in range( 4, 69 ):
	dp.append( dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] )

for _ in range( int( input() ) ):
	n = int( input( ) )

	print( dp[n] )
