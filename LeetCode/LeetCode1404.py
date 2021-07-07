# LeetCode1404_NumberOfStepsToReduceANumberInBinaryRepresentationToOne.py
class Solution:
	def numSteps( self, s: str ) -> int:
		num = 0
		last = len( s ) - 1
		for exp in range( 0, len( s ) ):
			num += int( s[last - exp ] ) * 2 ** exp

		count = 0
		while num != 1:
			if num % 2:
				num += 1
			else:
				num //= 2

			count += 1

		return count
