# Baekjoon15650_NandM2.py
N, M = map( int, input().split() )

nums = list( map( str, range( 1, N + 1 ) ) )

# method 1 (56ms)
def backtrack( prev, size ):
	if size == M:
		print( ' '.join( prev ) )
	else:
		for n in nums:
			if ( (not prev) or (n > prev[-1]) ):
				backtrack( prev + [ n ], size + 1 )

backtrack( [], 0 )
