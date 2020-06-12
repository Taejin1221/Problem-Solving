# Baekjoon05086_FactorAndMultiple.py
# https://www.acmicpc.net/problem/5086
import sys
read = sys.stdin.readline

a, b = map( int, read().split() )
while ( a or b ):
	if ( a % b == 0 ):
		print( 'multiple' )
	elif ( b % a == 0 ):
		print( 'factor' )
	else:
		print( 'neither' )

	a, b = map( int, read().split() )
