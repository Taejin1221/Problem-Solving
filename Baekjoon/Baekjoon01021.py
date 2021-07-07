# Baekjoon01021_RotateQueue.py
import collections

n, m = map( int, input().split() )
nums = list( map( int, input().split() ) )

q = [ 0 for _ in range( n ) ]
for n in nums:
	q[n - 1] = n

cnt = 0
deque = collections.deque( q )
for n in nums:
	idx = deque.index( n )

	left, right = idx - 0, len( deque ) - idx
	if left < right:
		for _ in range( left ):
			deque.append( deque.popleft() )
		cnt += left
	else:
		for _ in range( right ):
			deque.appendleft( deque.pop() )
		cnt += right
	deque.popleft()

print( cnt )
