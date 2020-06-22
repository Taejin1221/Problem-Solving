# Baekjoon11866_Josephus0.py
from collections import deque

n, k = map( int, input().split() )

peoples = deque( [ i for i in range( 1, n + 1 ) ] )
array = [ ]

while ( len( peoples ) ):
	for _ in range( k - 1 ):
		peoples.append(peoples.popleft())
	array.append( str( peoples.popleft() ) )

print( '<' + ', '.join(array) + '>' )
