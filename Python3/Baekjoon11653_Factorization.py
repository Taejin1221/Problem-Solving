# Baekjoon11653_Factorization.py
# https://www.acmicpc.net/problem/11653
n = int( input() )

results = [ ]

prime = [ False, False ] + [ True ] * ( n - 1 )
for i in range( 2, int( n ** .5 ) + 1 ):
	if prime[i]:
		while ( n % i == 0 ):
			results.append( i )
			n //= i
		if n != 1:
			for j in range( i * i, n + 1, i ):
				prime[j] = False
if n > 1:
	overPrime = [ ]
	for i in range( int( n ** .5 ) + 1, n + 1 ):
		if prime[i]:
			overPrime.append( i )

	while ( not prime[n] ):
		for p in overPrime:
			if n % p == 0:
				results.append( p )
				n //= p
				break
	results.append( n )

for r in results:
	print( r )
