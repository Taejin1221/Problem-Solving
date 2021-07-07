# LeetCode0202_HappyNumber.py
class Solution:
	def isHappy( self, n: int ) -> bool:
		prevNum = [ ]

		nStr = str( n )
		while n != 1:
			newN = 0
			for digit in nStr:
				newN += int( digit ) ** 2

			if newN in prevNum:
				return False
			else:
				prevNum.append( newN )

			n, nStr = newN, str( newN )

		return True
