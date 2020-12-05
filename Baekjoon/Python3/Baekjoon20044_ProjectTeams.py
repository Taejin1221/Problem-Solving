# Baekjoon20044_ProjectTeams.py
# https://www.acmicpc.net/problem/20044
n = int( input() )
n *= 2

ablities = list( map( int, input().split() ) )

ablities.sort()

minAblity = float('inf')
for i in range( n // 2 + 1 ):
	minAblity = min( minAblity, ablities[i] + ablities[n - 1 - i] )

print( minAblity)
