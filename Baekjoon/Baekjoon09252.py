# Baekjoon09252_LCS2.py
# https://www.acmicpc.net/problem/9252
str1 = input()
str2 = input()

dp = [ [ '' for _ in range( 1000 ) ] for _ in range( 1000 ) ]
for i, s1 in enumerate( str1 ):
	for j, s2 in enumerate( str2 ):
		if ( s1 == s2 ):
			if i and j:
				dp[i][j] = dp[i - 1][j - 1] + str(s1)
			else:
				dp[i][j] = s1
		else:
			if i and j:
				dp[i][j] = max( dp[i - 1][j], dp[i][j - 1], key = lambda x: len(x) )
			elif i:
				dp[i][j] = dp[i - 1][j]
			elif j:
				dp[i][j] = dp[i][j - 1]
			else:
				dp[i][j] = ''

print( len(dp[len(str1) - 1][len(str2) - 1] ) )
print( dp[len(str1) - 1][len(str2) - 1] )
