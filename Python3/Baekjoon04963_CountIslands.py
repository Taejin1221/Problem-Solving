# Baekjoon04963_CountIslands.py
import sys
input = sys.stdin.readline

w, h = map( int, input().split() )
while ( w and h ):
	grid = [ ]
	for _ in range( h ):
		grid.append( list( map( int, input().split() ) ) )

	maxRow, maxCol = h, w
	visited = [ [ False ] * maxCol for _ in range( maxRow ) ]

	count = 0
	for i in range( maxRow ):
		for j in range( maxCol ):
			if not visited[i][j]:
				visited[i][j] = True

				if grid[i][j]:
					q = [ ( i, j ) ]
					while q:
						currRow, currCol = q.pop( 0 )

						nextPos = [
							( currRow - 1, currCol - 1 ), # 1
							( currRow - 1, currCol ), # 2
							( currRow - 1, currCol + 1 ), # 3
							( currRow, currCol - 1 ), # 4
							( currRow, currCol + 1 ), # 5
							( currRow + 1, currCol - 1 ), # 6
							( currRow + 1 , currCol ), # 7
							( currRow + 1, currCol + 1 ) # 8
						]

						for nextRow, nextCol in nextPos:
							if ( ( -1 < nextRow < maxRow ) and ( -1 < nextCol < maxCol ) ):
								if not visited[nextRow][nextCol]:
									visited[nextRow][nextCol] = True
									if grid[nextRow][nextCol]:
										q.append( ( nextRow, nextCol ) )

					count += 1
	print( count )

	w, h = map( int, input().split() )
