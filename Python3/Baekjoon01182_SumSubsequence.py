# Baekjoon01182_SumSubsequence.py
# https://www.acmicpc.net/problem/1182
n, s = map( int, input().split() )
nums = list( map( int, input().split() ) )

def backtracking( idx, prevSum ):
	global count
	if prevSum == s:
		count += 1
	for i in range( idx, n ):
		backtracking( i + 1, prevSum + nums[i] )

count = 0
for i in range( 0, n ):
	backtracking( i + 1, nums[i] )
print( count )
