# Prob0027_RemoveElement.py
class Solution:
	def removeElement(self, nums: List[int], val: int) -> int:
		numsSize = len(nums)
		numElements = 0
		for i in range(numsSize):
			if (nums[i] is val):
				numElements += 1

		for i in range(numElements):
			nums.remove(val)

		return len(nums)