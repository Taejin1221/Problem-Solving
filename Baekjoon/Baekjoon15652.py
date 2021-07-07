# Baekjoon15652_NandM4.py
N, M = map( int, input().split() )
nums = list( map( str, range( 1, N + 1 ) ) )

# method 1 (68ms)
def backtrack( prev, size ):
	if size == M:
		print( ' '.join( prev ) )
	else:
		for n in nums:
			if (not prev) or (prev[-1] <= n):
				backtrack( prev + [ n ], size + 1 )

backtrack( [], 0 )

# method 2 (56ms)
from itertools import combinations_with_replacement
print( '\n'.join( map( ' '.join, combinations_with_replacement( nums, M ) ) ) )