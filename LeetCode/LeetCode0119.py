# LeetCode0119_Pascal'sTriangle2.py
class Solution:
	# method 1 : Iteration
	def getRow( self, row: int ) -> List[int]:
		tri = [ ] 
		if row >= 0:
			tri.append( 1 )
		if row >= 1:
			tri.append( 1 )

		for n in range( 1, row ):
			val1, val2 = tri[0], tri[1]
			for i in range( 1, n + 1 ):
				tri[i] = val1 + val2
				if ( i != n  ):
					val1, val2 = val2, tri[i + 1]
			tri.append( 1 )

		return tri

	# method 2 : Recursion
	def getRow( self, row: int ) -> List[int]:
		if row is 0:
			return [ 1 ]
		elif row is 1:
			return [ 1, 1 ]
		else:
			prevRow = self.getRow( row - 1 )
			currRow = [ 1 ] + [ (prevRow[i - 1] + prevRow[i]) for i in range( 1, row ) ] + [ 1 ]

			return currRow
