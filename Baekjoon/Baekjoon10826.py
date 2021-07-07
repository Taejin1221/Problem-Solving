# Baekjoon10826_Fibonacci4.py
# https://www.acmicpc.net/problem/10826
n = int( input() )

dp = [ 0, 1 ]
for i in range( 2, n + 1 ):
	dp.append( dp[i - 1] + dp[i - 2] )

print( dp[n] )