# LeetCode0118_Pascal'sTriangle.py
class Solution:
	def generate( self, row: int ) -> List[List[int]]:
		triangle = []

		if row >= 1:
			triangle.append( [ 1 ] )
		if row >= 2:
			triangle.append( [ 1, 1 ] )

		for n in range( 2, row ):
			for i in range( n + 1 ):
				if i is 0:
					triangle.append( [ 1 ] )
				elif ( i == n ):
					triangle[n].append( 1 )
				else:
					triangle[ n ].append( triangle[n - 1][ i - 1 ] + triangle[n - 1][ i ] )

		return triangle
