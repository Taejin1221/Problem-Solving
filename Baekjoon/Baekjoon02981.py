# Baekjoon02981_GRANICA.py
# https://www.acmicpc.net/probelm/2981
import sys
from math import gcd
input = sys.stdin.readline

nums = [ ]
time = int( input() )
for _ in range( time ):
	nums.append( int( input() ) )

nums.sort()

diff = [ nums[i + 1] - nums[i] for i in range( time - 1 ) ]

prevGCD = diff[0]
for d in diff[1 : ]:
	prevGCD = gcd( prevGCD, d )

sqrt = int( prevGCD ** .5 )
s = set()
for i in range( 2, sqrt + 1 ):
	if prevGCD % i == 0:
		s.add( i )
		s.add( prevGCD // i )

results = sorted( list( s ) )
for r in results:
	print( r, end = ' ')
print( prevGCD )
