# Baekjoon01181_SortWord.py
import sys
input = sys.stdin.readline

words = []
for _ in range( int( input() ) ):
	words.append( input().rstrip() )

# method 1 (96ms)
for w in sorted( sorted( set( words ) ), key = lambda x: len( x ) ):
	print( w )

# method 2 (92ms)
words = list( set( words ) )
words.sort()
words.sort( key = lambda x: len( x ) )
for w in words:
	print( w )
