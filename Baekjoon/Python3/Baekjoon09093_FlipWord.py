# Baekjoon09093_FlipWord.cpp
# https://www.acmicpc.net/problem/9093
for _ in range( int( input() ) ):
	l =  input().split()
	for s in l:
		print( ''.join( reversed( s ) ), end = ' ' )
	print()
