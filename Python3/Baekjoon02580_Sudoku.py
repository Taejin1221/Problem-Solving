# Baekjoon02580_Sudoku.py
def isValid( curr, row, col ):
	# Check row and column
	for i in range( 9 ):
		if row != i and board[i][col] == curr:
			return False

		if col != i and board[row][i] == curr:
			return False

	# Check 3x3
	center = ( (row - ( row % 3 ) + 1), (col - ( col % 3 ) + 1) )
	for r in range( center[0] - 1, center[0] + 2 ):
		for c in range( center[1] - 1, center[1] + 2 ):
			if ( r != row or c != col ) and board[r][c] == curr:
				return False

	return True

def FillSudoku( row, col, idx ):
	if idx == size:
		for i in range( 1, 10 ):
			if isValid( i, row, col ):
				board[row][col] = i
				return True
		return False
	else:
		for i in range( 1, 10 ):
			if isValid( i, row, col ):
				board[row][col] = i
				if FillSudoku( *zeros[idx], idx + 1 ):
					return True
				else:
					board[row][col] = 0
		return False

board = [ ]
for _ in range( 9 ):
	board.append( list( map( int, input().split() ) ) )

zeros = [ ]
for row in range( 0, 9 ):
	for col in range( 0, 9 ):
		if board[row][col] == 0:
			zeros.append( ( row, col ) )

size = len( zeros )
FillSudoku( *zeros[0], 1 )
for row in range( 0, 9 ):
	for col in range( 0, 9 ):
		print( board[row][col], end = ' ' )
	print()
