# LeetCode1266_MinimumTimeVisitingAllPoints.py
class Solution:
	def minTimeToVisitAllPoints( self, points: List[List[int]] ) -> int:
		second = 0

		for i in range( len( points ) - 1 ):
			temp = ( abs( points[i][0] - points[i + 1][0] ),
				abs( points[i][1] - points[i + 1][1] ) )
			second += min(temp) + abs( temp[0] - temp[1] )

		return second

	def minTimeToVisitAllPoints( self, points: List[List[int]] ) -> int:
		second = 0

		for i in range( len( points ) - 1 ):
			temp = ( abs( points[i][0] - points[i + 1][0] ),
				abs( points[i][1] - points[i + 1][1] ) )
			second += max(temp)

		return second

	def minTimeToVisitAllPoints( self, points: List[List[int]] ) -> int:
		second = 0

		for i in range( len( points ) - 1 ):
			temp = ( abs( points[i][0] - points[i + 1][0] ),
				abs( points[i][1] - points[i + 1][1] ) )

			second += temp[0] if temp[0] > temp[1] else temp[1]

			if temp[0] > temp[1]:
				second += temp[0]
			else:
				second += temp[1]

		return second
