# Baekjoon04153_RightTriangle.py
import sys
input = sys.stdin.readline

abc = list( map( int, input().split() ) )
while ( abc.count( 0 ) is not 3 ):
	c = abc.remove( max( abc ) )
	a, b = abc
	if ( a ** 2 + b ** 2 == c ** 2 ):
		print( 'right' )
	else:
		print( 'wrong' )

	abc = list( map( int, input().split() ) )