# Baekjoon01712_Break-EvenPoint.py
A, B, C = map( int, input().split() )

if ( B >= C ):
	print( -1 )
else:
	n = A // ( C - B )

	print( n + 1 )

print( -1 if B >= C else ( A // ( C - B ) + 1) )