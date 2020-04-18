# Baekjoon10773_Zero.py
import sys

# method 1 (124ms) : readline
n = int( sys.stdin.readline() )

stck = [ ]
for _ in range( n ):
	num = int( sys.stdin.readline() )
	stck.append( num ) if num else stck.pop()

# method 2 (92ms) : stdin
sys.stdin.readline()

stck = [ ]
for num in map( int, sys.stdin ):
	stck.append( num ) if num else stck.pop()


print( sum( stck ) )
