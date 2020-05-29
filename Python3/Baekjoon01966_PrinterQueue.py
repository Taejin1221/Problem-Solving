# Baekjoon01966_PrinterQueue.py
import sys
input = sys.stdin.readline

import collections

for _ in range( int( input() ) ):
	n, m = map( int, input().split() )
	docs = collections.deque( list( map( int, input().split() ) ) )

	cnt, idx, size = 0, m, n
	while ( idx != -1 ):
		maxVal = max( docs )
		while ( maxVal > docs[0] ):
			docs.append( docs.popleft() )

			idx = ( size + ( idx - 1 ) ) % size

		cnt += 1; size -= 1; idx -= 1
		docs.popleft()

	print( cnt )

