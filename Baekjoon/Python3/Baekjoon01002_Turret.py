# Baekjoon01002_Turret.py
import sys
input = sys.stdin.readline

def DistanceSqare( p1: tuple, p2: tuple) -> int:
	return ( p1[0] - p2[0] ) ** 2 + ( p1[1] - p2[1] ) ** 2

for _ in range( int( input() ) ):
	x1, y1, r1, x2, y2, r2 = map( int, input().split() )
	dist = DistanceSqare( (x1, y1), (x2, y2) )
	maxR = max( r1, r2 )
	minR = min( r1, r2 )

	if (x1, y1, r1) == (x2, y2, r2):
		print( -1 )
	elif maxR ** 2 > dist:
		if dist == ( maxR - minR ) ** 2:
			print( 1 )
		elif dist < ( maxR - minR ) ** 2:
			print( 0 )
		else:
			print( 2 )
	elif dist == (r1 + r2) ** 2:
		print( 1 )
	elif dist > (r1 + r2) **2:
		print( 0 )
	else:
		print( 2 )
