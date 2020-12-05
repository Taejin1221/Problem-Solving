# Baekjoon01931.py
import sys
input = sys.stdin.readline

n = int( input() )

meetings = [ ]
for _ in range( n ):
	s, e = map( int, input().split() )
	meetings.append( ( s, e ) )

meetings.sort( )
meetings.sort( key = lambda x: x[1] )

count = 1
prevEnd = meetings[0][1]
for meeting in meetings[1 : ]:
	if ( meeting[0] >= prevEnd ):
		count += 1
		prevEnd = meeting[1]

print( count )
