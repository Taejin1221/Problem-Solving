# Baekjoon06996_Anagram.py
# https://www.acmicpc.net/problem/6996
import sys
input = sys.stdin.readline

n = int( input() )
for _ in range( n ):
	a, b = input().split()

	aDict = [ 0 for _ in range( 26 ) ]
	bDict = [ 0 for _ in range( 26 ) ]
	for i in a:
		aDict[ord( i ) - ord( 'a' )] += 1

	for i in b:
		bDict[ord( i ) - ord( 'a' )] += 1

	isAna = True
	for tempA, tempB in zip( aDict, bDict ):
		if ( tempA != tempB	 ):
			isAna = False
			break

	# print( aDict, bDict )

	if ( isAna and ( len(a) == len(b) ) ):
		print(f'{a} & {b} are anagrams.' )
	else:
		print(f'{a} & {b} are NOT anagrams.' )

