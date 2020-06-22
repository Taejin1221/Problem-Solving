# LeetCode1046_LastStoneWeight.py
class Solution:
	# method 1 (28ms) : Search
	def lastStoneWeight( self, stones: List[int] ) -> int:
		while len( stones ) > 1:
			max1 = max( stones ); stones.remove( max1 )
			max2 = max( stones ); stones.remove( max2 )

			if max1 == max2:
				continue
			else:
				stones.append( max1 - max2 )

		if len( stones ):
			return stones[0]
		else:
			return 0
