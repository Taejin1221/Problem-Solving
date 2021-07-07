# Baekjoon02231_Decomposition.py
n = int( input() )

def Decomposition( n ):
	sum = n
	while( n ):
		sum += n % 10
		n //= 10
	return sum

ans = 0
for i in range( 1, n ):
	if ( Decomposition( i ) == n ):
		ans = i
		break

print( ans )
