# LeetCode0509_FibonacciNumber.py
class Solution:
	# method 1 (56ms) : Recursion with Memorization
	table = [ 0, 1 ]
	def fib( self, N: int ) -> int:
		if len( self.table ) <= N:
			result = self.fib( N - 1 ) + self.fib( N - 2 )
			self.table.append( result )

			return result
		else:
			return self.table[N]

	# method 2 (20ms) : Iteration
	def fib( self, N: int ) -> int:
		if N < 2:
			return N
		else:
			f1, f2 = 0, 1
			for _ in range( 2, N + 1 ):
				f3 = f1 + f2
				f2, f1 = f3, f2

			return f3


	# method 3 (48ms) : Iteration with Memorization
	def fib( self, N: int ) -> int:
		fibo = [ 0, 1 ]

		for i in range( 2, N + 1 ):
			fibo.append( fibo[i - 1] + fibo[i - 2] )

		return fibo[N]
