# Baekjoon09020_GoldbachConjecture.py
import sys
input = sys.stdin.readline

N = 10000
prime = [ False, False ] + [ True ] * ( N - 1 )
for i in range( 2, N + 1 ):
	if ( not prime[i] ): continue
	for j in range( i * 2, N + 1, i ):
		prime[j] = False

for _ in range( int( input() ) ):
	n = int( input() )
	halfN = n // 2

	for i in range( halfN, 1, -1 ):
		if ( prime[i] and prime[n - i] ):
			print( i, n - i )
			break