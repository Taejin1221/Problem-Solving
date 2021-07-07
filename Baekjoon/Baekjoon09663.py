# Baekjoon09633_N-Queen.py
import sys
n = int( sys.stdin.readline() )

def isValid( queens, row, col ):
	for q in queens:
		if ( ( q[1] == col ) or ( q[0] - q[1] == row - col ) or ( q[0] + q[1] == row + col ) ):
			return False
	return True

def nqueen( size, queens ):
	global count
	if size == n:
		count += 1
	else:
		for col in range( n ):
			if isValid( queens, size, col ):
				nqueen( size + 1, queens + [ ( size, col ) ] )

count = 0
for col in range( n ):
	nqueen( 1, [ ( 0, col ) ] )

print( count )
