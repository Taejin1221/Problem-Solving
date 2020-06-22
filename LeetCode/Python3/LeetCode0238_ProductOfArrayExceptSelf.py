# LeetCode0238_ProductOfArrayExceptSelf.py
class Solution:
	def productExceptSelf( self, nums: List[int] ) -> List[int]:
		zero = False
		zeroTwo = False
		allProduct = 1
		for n in nums:
			if n != 0:
				allProduct *= n
			else:
				if zero:
					zeroTwo = True
				else:
					zero = True

		
		rtrnList = [ ]
		if not zero:
			for n in nums:
				rtrnList.append( allProduct // n )
		else:
			if zeroTwo:
				rtrnList = [ 0 ] * len( nums )
			else:
				for n in nums:
					if n != 0:
						rtrnList.append( 0 )
					else:
						rtrnList.append( allProduct )			

		return rtrnList
