# LeetCode0064_MinimumPathSum.py
class Solution:
	def minPathSum( self, grid: List[List[int]] ) -> int:
		m, n = len( grid ), len( grid[0] )

		minPath = [ [ ] for _ in range( m ) ]
		for i in range( m ):
			for j in range( n ):
				if (i == 0) and (j == 0):
					minPath[i].append( grid[i][j] )

				elif i == 0:
					minPath[i].append( minPath[i][j - 1] + grid[i][j] )
				elif j == 0:
					minPath[i].append( minPath[i - 1][j] + grid[i][j] )
				else:
					minPath[i].append( min( minPath[i][j - 1], minPath[i - 1][j] ) + grid[i][j] )

		return minPath[m - 1][n - 1]
