# Baekjoon01978_FindPrimeNumber.py
cnt = 0
prime = [ i for i in range( 2, 1001 ) ]
for p in prime:
	for i in range( 2, 1000 // p + 1 ):
		notPrime = p * i
		if notPrime in prime:
			prime.remove( notPrime )

input()
for i in map( int, input().split() ):
	if ( i in prime ):
		cnt += 1

print( cnt )