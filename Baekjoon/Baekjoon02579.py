# Baekjoon02579_ClimbingStair.py
# https://www.acmicpc.net/problem/2579
import sys
input = sys.stdin.readline

n = int( input() )
stair = [  ]
for _ in range( n ):
	stair.append( int( input() ) )

if ( n == 1 ):
	print( stair[0] )
else:
	# dp[n][0] -> n칸까지 올라올 때의 max 값(이전에 2칸으로 올라온 경우)
	# dp[n][1] -> n칸까지 올라올 때의 max 값(이전에 1칸으로 올라온 경우)

	dp = [ ]
	dp.append( [ stair[0], stair[0] ] )
	dp.append( [ stair[1], stair[0] + stair[1] ] )
	for i in range( 2, n ):
		temp = [ ]
		temp.append( max(dp[i - 2][0], dp[i - 2][1]) + stair[i] )
		temp.append( dp[i - 1][0] + stair[i] )

		dp.append( temp )

	print( max( dp[n - 1][0], dp[n - 1][1] ) )
