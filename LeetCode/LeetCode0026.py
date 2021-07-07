# LeetCode0026_RemoveDuplicatesFromSortedArray.py
class Solution:
	def removeDuplicates( self, nums: List[int] ) -> int:
		if not nums:
			return None

		idx, length = 1, len( nums )

		val = nums[0]
		while ( idx < length ):
			if val == nums[idx]:
				del nums[idx]
				length -= 1
			else:
				val = nums[idx]
				idx += 1
		return length

	def removeDuplicates( self, nums: List[int] ) -> int:
		if not nums:
			return None

		idx, swap = 1, 1
		val = nums[0]

		while ( idx < len( nums) ):
			if val != nums[idx]:
				val = nums[idx]
				nums[swap] = val
				swap += 1
			idx += 1

		return swap
