# LeetCode1295_FindNumbersWithEvenNumberOfDigits.py
class Solution:
	def findNumbers( self, nums: List[int] ) -> int:
		strs = [ 1 for n in nums if len(str(n)) % 2 == 0 ]

		return len( strs )

	def findNumbers( self, nums: List[int] ) -> int:
		count = 0

		for n in nums:
			if len(str(n)) % 2 == 0:
				count += 1

		return count