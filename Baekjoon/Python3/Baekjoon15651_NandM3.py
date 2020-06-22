# Baekjoon15651_NandM3.py
N, M = map( int, input().split() )
nums = list( map( str, range( 1, N + 1 ) ) )

# method 1 (764ms)
def backtrack( prev, size ):
	if size == M:
		print( ' '.join( prev ) )
	else:
		for n in nums:
			backtrack( prev + [ n ], size + 1 )

backtrack( [], 0 )

# method 2 (292ms)
from itertools import product
print( '\n'.join( [ ' '.join( pro ) for pro in product( nums, repeat = M ) ] ) )

# method3 (248ms)
print( '\n'.join( list( map( ' '.join, product( nums, repeat = M ) ) ) ) )