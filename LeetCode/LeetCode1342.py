# LeetCode1342_NumberOfStepsToReduceANumberToZero.py
class Solution:
	def numberOfSteps( self, num: int ) -> int:
		cnt = 0
		while ( num > 0 ):
			# if num is odd
			if ( num % 2 ):
				num -= 1
			else:
				num //= 2
			cnt += 1

		return cnt