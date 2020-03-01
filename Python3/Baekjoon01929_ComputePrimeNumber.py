# Baekjoon01929_ComputePrimeNumber.py
M, N = map( int, input().split() )

prime = [ False, False ] + [ True ] * ( N - 1 )
for i in range( 2, N + 1 ):
	if ( not prime[i] ): continue
	for j in range( i * 2, N + 1, i ):
		prime[j] = False

for i in range( M, N + 1 ):
	if ( prime[i] ):
		print( i )