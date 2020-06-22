# Prob1281_SubtractProductSum.py
class Solution:
	def subtractProductAndSum(self, n: int) -> int: 
		prodAll = 1
		sumAll = 0

		quo = n
		while (quo is not 0):
			rem = quo % 10
			prodAll = prodAll * rem
			sumAll = sumAll + rem
			quo = quo // 10


		return (prodAll - sumAll)
