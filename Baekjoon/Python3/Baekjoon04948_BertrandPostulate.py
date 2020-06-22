# Baekjoon04948_BertrandPostulate.py
N = 123456 * 2
prime = [ False, False ] + [ True ] * ( N - 1 )
for i in range( 2, N + 1 ):
	if ( not prime[i] ): continue
	for j in range( i * 2, N + 1, i ):
		prime[j] = False

n = int(input())
while ( n is not 0 ):
	print( prime[ n + 1 : 2 * n + 1].count( True ) )

	n = int( input() )