# Baekjoon20152_GameAddiction.py
# https://www.acmicpc.net/problem/20152
start, end = map( int, input().split() )

if ( start > end ):
	start, end = end, start

dp = [ [ 0 for _ in range( end + 1 ) ] for _ in range( end + 1 ) ]

'''
일반 좌표계와 다르게 *인 구역을 침수되지 않은 구역이라고 생각

****
***0
**00
*000
'''
for i in range( start, end + 1 ):
	for j in range( start, i + 1 ):
		if ( j == start ):
			dp[i][j] = 1
		else:
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

print( dp[end][end] )
