# LeetCode0062_UniquePath.py
# https://leetcode.com/problems/unique-paths/
class Solution:
	def uniquePaths( self, row: int, col: int ) -> int:
		dp = [ [ 0 for _ in range( col ) ] for _ in range( row ) ]

		for i in range( col ):
			dp[0][i] = 1

		for i in range( row ):
			dp[i][0] = 1

		for i in range( 1, row ):
			for j in range( 1, col ):
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

		return dp[row - 1][col - 1]
