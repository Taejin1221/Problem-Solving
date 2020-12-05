# Baekjoon10164_PathOnGrid.py
# https://www.acmicpc.net/problem/10164
def GetNumberOfPath( row, col ):
	dp = [ [ 0 for _ in range( col ) ] for _ in range( row ) ]

	for i in range( row ):
		dp[i][0] = 1

	for i in range( col ):
		dp[0][i] = 1

	for i in range( 1, row ):
		for j in range( 1, col ):
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

	return dp[row - 1][col - 1]

n, m, k = map( int, input().split() )

midRow, midCol = 0, 0
num, isFind = 1, False
for i in range( n ):
	for j in range( m ):
		if ( num == k ):
			midRow = i
			midCol = j
			isFind = True
			break
		num += 1

	if ( isFind ):
		break

print( GetNumberOfPath( midRow + 1, midCol + 1 ) * GetNumberOfPath( n - midRow, m - midCol ) )
