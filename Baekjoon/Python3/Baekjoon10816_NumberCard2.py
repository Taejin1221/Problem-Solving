# Baekjoon10816_NumberCard2.py
# https://www.acmicpc.net/problem/10816
import sys
input = sys.stdin.readline

n = int( input() )
oldCards = list( map( int, input().split() ) )
input()
newCards = list( map( int, input().split() ) )

table = { }
for n in oldCards:
	if n in table:
		table[n] += 1
	else:
		table[n] = 1

for card in newCards:
	if card in table:
		print( table[card], end = ' ' )
	else:
		print( 0, end = ' ' )
