# LeetCode0053_MaximumSubarray.py
class Solution:
	def maxSubArray( self, nums: List[int] ) -> int:
		max1, max2 = nums[0], nums[0]
		for num in nums[1 : ]:
			max1 = max( max1 + num, num )
			max2 = max( max2, max1 )

		return max2
