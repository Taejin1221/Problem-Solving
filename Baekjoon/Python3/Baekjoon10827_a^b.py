# Baekjoon10827_a^b.py
# https://www.acmicpc.net/problem/10827
a, b = input().split()

decimalFraction = len( a ) - a.index( '.' ) - 1
a = int( a.replace( '.', '' ) )
b = int( b )

ans = str( a ** b )
ansLen = len( ans )

decimalLen = decimalFraction * b
if ( ansLen > decimalLen ):
	ansDecimalFraction = ansLen - decimalLen
	print( ans[ : ansDecimalFraction] + '.' + ans[ansDecimalFraction : ] )
else:
	print( '0.' + '0' * (decimalLen - ansLen) + ans )
