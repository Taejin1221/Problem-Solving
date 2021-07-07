# LeetCode0283_MoveZeores.py
class Solution:
	def moveZeroes( self, nums: List[int] ) -> None:
		zero = 0
		while zero < len( nums ) and nums[zero]:
			zero += 1

		if zero == len( nums ):
			return

		for nonZero in range( len( nums ) ):
			if nums[nonZero] != 0 and zero < nonZero:
				nums[zero], nums[nonZero] = nums[nonZero], nums[zero]
				while nums[zero]:
					zero += 1
