# Baekjoon14889_StartAndLink.py
import sys
from itertools import combinations

input = sys.stdin.readline

N = int( input() )
S = []
for _ in range( N ):
	S.append( list( map( int, input().split() ) ) )

teams = list( combinations( range( 0, N ), N // 2 ) )
length = len( teams )
starts, links = teams[ : length // 2 ], teams[ length // 2 : ]
links.reverse()

min = float( 'inf' )
for start, link in zip( starts, links ):
	startSum, linkSum = 0, 0
	for s1 in start:
		for s2 in start:
			if s1 is not s2:
				startSum += S[s1][s2]

	for l1 in link:
		for l2 in link:
			if l1 is not l2:
				linkSum += S[l1][l2]

	diff = abs(startSum - linkSum)
	min = min if min < diff else diff

print( min )
