# LeetCode1380_LuckyNumbersInAMatrix.py
class Solution:
	def luckyNumbers( self, matrix: List[List[int]] ) -> List[int]:
		luckys = []

		for i in range( len( matrix ) ):
			for j in range( len( matrix[0] ) ):
				value = matrix[i][j]

				column = [ matrix[x][j] for x in range( len( matrix ) ) ]
				row = matrix[i]

				if ( ( min(row) == value ) and ( max(column) == value ) ):
					luckys.append( value )

		return luckys