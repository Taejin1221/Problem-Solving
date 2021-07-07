class Solution:
	def numIslands( self, grid: List[List[str]] ) -> int:
		if not grid:
			return 0

		maxRow, maxCol = len( grid ), len( grid[0] )
		visited = [ [ False ] * maxCol for _ in range( maxRow ) ]
		
		count = 0
		for i in range( maxRow ):
			for j in range( maxCol ):
				if not visited[i][j]:
					visited[i][j] = True

					if grid[i][j] == '1':
						q = [ ( i, j ) ]
						while q:
							currRow, currCol = q.pop( 0 )

							nextPos = [
								( currRow - 1, currCol ), # Up
								( currRow, currCol - 1 ), # Left
								( currRow, currCol + 1 ), # Right
								( currRow + 1 , currCol ), # Bottom
							]

							for nextRow, nextCol in nextPos:
								if ( ( -1 < nextRow < maxRow ) and ( -1 < nextCol < maxCol ) ):
									if not visited[nextRow][nextCol]:
										visited[nextRow][nextCol] = True
										
										if grid[nextRow][nextCol] == '1':
											q.append( ( nextRow, nextCol ) )

						count += 1

		return count
