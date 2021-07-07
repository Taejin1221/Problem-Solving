# LeetCode0070_ClimbingStairs.py
class Solution:
	table = [ 0, 1, 2 ]
	def climbStairs( self, n: int ) -> int:
		if len( self.table ) > n:
			return self.table[n]
		else:
			result = self.climbStairs( n - 1 ) + self.climbStairs( n - 2 )

			self.table.append( result )

			return result


	table = { 0: 0, 1: 1, 2: 2 }
	def climbStairs( self, n: int ) -> int:
		if n in self.table:
			return self.table[n]
		else:
			self.table[n] = self.climbStairs( n - 1 ) + self.climbStairs( n - 2 )
			return self.table[n]


	def climbStairs( self, n: int ) -> int:
		table = { }

		table[0] , table[1], table[2] = 0, 1, 2
		for i in range( 3, n + 1 ):
			table[i] = table[i - 1] + table[i - 2]

		return table[n]


	def climbStairs( self, n: int ) -> int:
		table = [ 0, 1, 2 ]

		for i in range( 3, n + 1 ):
			table.append( table[i - 1] + table[i - 2] )

		return table[n]
