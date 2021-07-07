# LeetCode_PerformStringShifts.py
class Solution:
	def stringShift( self, s: str, shift: List[List[int]] ) -> str:
		operation = shift[0]

		for sh in shift[1 : ]:
			if operation[0] == sh[0]:
				operation[1] += sh[1]
			else:
				amount = operation[1] - sh[1]
				if amount < 0:
					operation = [ sh[0], -amount ]
				else:
					operation[1] = amount

		leng = len( s )
		amount = operation[1] % leng

		newStr = ''
		if operation[0] == 0:
			newStr = s[amount : ] + s[ : amount]
		else:
			newStr = s[leng - amount : ] + s[ : leng - amount]

		return newStr