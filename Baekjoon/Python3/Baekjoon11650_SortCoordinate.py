# Baekjoon11650_SortCoordinate.py
import sys
input = sys.stdin.readline

points = []
for _ in range( int( input() ) ):
    point = tuple( map( int, input().split() ) )
    points.append( point )
for x, y in sorted( points ):
    print( x, y )