# Baekjoon01269_SymmetricDifference.py
import sys

input = sys.stdin.readline

n, m = map( int, input().split() )
A = set( map( int, input().split() ) )
B = set( map( int, input().split() ) )

diff1 = A - B
diff2 = B - A

C = diff1 | diff2

print( len( C ) )
