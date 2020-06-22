# Baekjoon15649_NandM1.py
N, M = map( int, input().split() )
nums = [ str(x) for x in range( 1, N + 1 ) ]

# method 1 (152ms)
def backtrack( prev, size ):
	if size == M:
		print( ' '.join( prev ) )
	else:
		for n in nums:
			if n not in prev:
				backtrack( prev + [n], size + 1 )

backtrack( [], 0 )

# method 2 (80ms)
for perm in permutations( nums, M ):
	print( ' '.join( perm ) )

# method 3 (64ms)
print( '\n'.join( [ ' '.join( perm ) for perm in permutations( nums, M ) ] ) )
