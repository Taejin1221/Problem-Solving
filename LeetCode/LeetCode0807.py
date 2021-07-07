# LeetCode0807_MaxIncreaseToKeepCitySkyline.py
class Solution:
	def maxIncreaseKeepingSkyline( self, grid: List[List[int]] ) -> int:
		count = 0
		rowSize, colSize = len( grid ), len( grid[0] )

		for i in range( rowSize ):
			for j in range( colSize ):
				row = grid[i]
				col = [ grid[x][j] for x in range( rowSize ) ]

				count += min( max(row), max(col) ) - grid[i][j]

		return count

	def maxIncreaseKeepingSkyline( self, grid: List[List[int]] ) -> int:
		count = 0
		rowSize, colSize = len( grid ), len( grid[0] )
		rowMaxes = [ max( rows ) for rows in grid ]
		colMaxes = [ max( [ grid[i][j] for i in range( rowSize ) ] ) for j in range( colSize ) ]

		for i in range( rowSize ):
			for j in range( colSize ):
				count += min( rowMaxes[i], colMaxes[j] ) - grid[i][j]

		return count
