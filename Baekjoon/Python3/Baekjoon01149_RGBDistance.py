# Baekjoon01149_RGBDistance.py
# https://acmicpc.net/problem/1149
import sys
sys.setrecursionlimit(99999)

time = int(sys.stdin.readline())
colorCost = [ ]
for _ in range( time ):
	colorCost.append( list( map( int, sys.stdin.readline().split() ) ) )

table = { }
def CalDistance( n: int, prevColor: int ) -> int:
	if n in table and prevColor in table[n]:
		return table[n][prevColor]
	if n:
		costs = [ ]
		for c in range( 3 ):
			if c != prevColor:
				costs.append( CalDistance( n - 1, c ) + colorCost[n - 1][prevColor] )
		minCosts = min(costs)
		if n not in table:
			table[n] = { prevColor : minCosts }
		else:
			table[n][prevColor] = minCosts

		return minCosts
	else:
		return 0

costs = [ ]
for i in range( 3 ):
	costs.append( CalDistance( time, i ) )
print( min(costs) )
