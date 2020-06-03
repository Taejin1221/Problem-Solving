# Baekjoon06603_Lotto.py
# https://www.acmicpc.net/problem/6603
import sys

def backtraking( size, arr, idx ):
	if size == 6:
		lottoNums.append( arr )
	else:
		for i in range( idx, time ):
			backtraking( size + 1, arr + [ nums[i] ], i + 1 )


nums = list( map( int, sys.stdin.readline().split() ) )
while ( nums[0] ):
	time = nums[0]
	nums = nums[1 : ]
	lottoNums = [ ]

	backtraking( 0, [ ], 0 )
	for lotto in lottoNums:
		for l in lotto:
			print( l, end = ' ')
		print( '' )
	print( '' )

	nums = list( map( int, sys.stdin.readline().split() ) )
