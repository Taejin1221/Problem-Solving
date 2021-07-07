# LeetCode1390_FourDivisors.py
class Solution:
	def sumFourDivisors( self, nums: List[int] ) -> int:
		sums = 0

		for n in nums:
			divisors = set()
			for i in range( 1, int(n ** .5) + 1 ):
				if n % i == 0:
					divisors.add( n // i )
					divisors.add( i )

					if len( divisors ) > 4:
						break

			if len( divisors ) == 4:
				sums += sum( divisors )

		return sums
