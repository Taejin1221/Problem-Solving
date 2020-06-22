# LeetCode1436_DestinationCity.py
class Solution:
	def destCity( self, paths: List[List[str]] ) -> str:
		startCity = set()

		for path in paths:
			startCity.add( path[0] )

		for path in paths:
			if path[1] not in startCity:
				return path[1]
