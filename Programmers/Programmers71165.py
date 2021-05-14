# Programmers71165.py
# https://programmers.co.kr/learn/courses/11133/lessons/71165
# COS Pro 1급 Python 모의고사 part 3 1번
import collections

def solution(garden):
	rowChange, colChange = [ -1, 0, 0, 1 ], [ 0, -1, 1, 0 ]

	time = 0
	rowSize, colSize = len( garden ), len( garden[0] )
	totalSize = rowSize * colSize
	
	q = collections.deque()
	
	zero = 0
	visited = [ [ False for _ in range( colSize ) ] for _ in range( rowSize ) ]
	for i in range( rowSize ):
		for j in range( colSize ):
			if ( garden[i][j] ):
				zero += 1
				visited[i][j] = True
				q.append( ( i, j ) )
	
	while ( q and zero < totalSize ):
		gen = len( q )
		for _ in range( gen ):
			currRow, currCol = q.popleft()
			for rr, cc in zip( rowChange, colChange ):
				newRow, newCol = currRow + rr, currCol + cc
				if ( ( 0 <= newRow < rowSize ) and ( 0 <= newCol < colSize ) ):
					if ( not visited[newRow][newCol] ):
						zero += 1
						visited[newRow][newCol] = True
						q.append( ( newRow, newCol ) )
						
		time += 1
		
	return time
