# LeetCode1413_MinimumValueToGetPositiveStepByStepSum.py
class Solution:
	def minStartValue( self, nums: List[int] ) -> int:
		sumNums = sum( nums )
		if sumNums < 0:
			startVal = -sumNums + 1
		else:
			startVal = 1

		while True:
			nextVal = startVal
			for n in nums:
				nextVal += n
				if nextVal < 1:
					startVal += 1
					break
			else:
				break

		return startVal
