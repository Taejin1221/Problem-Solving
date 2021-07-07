# Baekjoon02581_PrimeNumber.py
M = int( input() )
N = int( input() )

prime = [ i for i in range( 2, N + 1 ) ]
for p in prime:
	for i in range( 2, N // p + 1 ):
		notPrime = p * i
		if notPrime in prime:
			prime.remove( notPrime )

startPoint = False
for i in range( M, N + 1 ):
	if ( i in prime ):
		startPoint = prime.index( i )
		break

if ( startPoint is not False ):
	temp  = prime[ startPoint : ]
	print( sum( temp ) )
	print( temp[0] )
else:
	print( -1 )
