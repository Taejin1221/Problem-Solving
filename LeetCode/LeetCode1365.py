# LeetCode1365_HowManyNumbersAreSmallerThanTheCurrentNumber.py
class Solution:
	def smallerNumbersThanCurrent( self, nums ):
		counts = [ 0 ] * ( max( nums ) + 1 )
		for n in nums:
			counts[n] += 1

		rtrnNum = []
		for n in nums:
			rtrnNum.append( sum( counts[ : n ] ) )

		rtrnNum = [ sum( counts[ : x]) for x in nums ]

		return rtrnNum
