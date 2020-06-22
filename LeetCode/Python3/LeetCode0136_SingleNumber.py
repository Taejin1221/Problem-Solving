# LeetCode0136_SingleNumber.py
class Solution:
	def singleNumber( self, nums: List[int] ) -> int:
		table = { }

		for num in nums:
			if num in table:
				table[num] += 1
			else:
				table[num] = 1

		for num in table:
			if table[num] == 1:
				return num
