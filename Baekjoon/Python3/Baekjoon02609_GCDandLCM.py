# Baekjoon02609_GCDandLCM.py
# https://www.acmicpc.net/problem/2609

n, m = map( int, input().split() )

# Euclidean Algorithm
def GCD( n, m ):
	if ( m > n ):
		n, m = m, n

	if n % m == 0:
		return m
	else:
		return GCD( m, n % m )

# Brute Force
def LCM( n, m ):
	if ( m > n ):
		n, m = m, n

	start = n // gcd
	while True:
		num = gcd * start
		if num % n == 0 and num % m == 0:
			return num
		start += 1

def LCM( n, m ):
	return n * m // gcd

gcd = GCD( n, m )
print( gcd )
print( LCM( n, m ) )
