# LeetCode1401_CircleAndRectangleOverlapping.py
class Solution:
	def checkOverlap( self, radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int ) -> bool:
		def disSquare( pos1, pos2 ):
			x = ( pos1[0] - pos2[0] ) ** 2
			y = ( pos1[1] - pos2[1] ) ** 2

			return x + y

		if ( x1 <= x_center and x_center <= x2 ) and ( y1 <= y_center and y_center <= y2 ):
			return True

		edges = [ ( x, y1 ) for x in range( x1, x2 + 1 ) ]
		edges += [ ( x, y2 ) for x in range( x1, x2 + 1 ) ]
		edges += [ ( x1, y ) for y in range( y1 + 1, y2 ) ]
		edges += [ ( x2, y ) for y in range( y1 + 1, y2 ) ]
		center = ( x_center, y_center )

		for edge in edges:
			if ( disSquare( edge, center ) <= ( radius ** 2 ) ):
				return True

		return False
