# LeetCode1399_CountLargestGroup.py
class Solution:
	def countLargestGroup( self, n: int ) -> int:
		def digitSum( n ):
			sum = 0
			while n:
				sum += n % 10
				n //= 10

			return sum

		groups = { }
		maxN, count = 0, 0
		for i in range( 1, n + 1 ):
			sumN = digitSum( i )

			if sumN in groups:
				groups[sumN] += 1
			else:
				groups[sumN] = 1

			if maxN < groups[sumN]:
				maxN = groups[sumN]
				count = 1
			elif maxN == groups[sumN]:
				count += 1

		return count
