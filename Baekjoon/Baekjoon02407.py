# Baekjoon02407_Combinations.py
n, m = map( int, input().split() )

dp = [ ]

for i in range( n + 1 ):
	dp.append( [ ] )
	dp[i].append( 1 )
	for j in range( 1, i ):
		dp[i].append( dp[i - 1][j - 1] + dp[i - 1][j] )
	dp[i].append( 1 )

print( dp[n][m] )