# Baekjoon01018_RecoloringChessBoard.py
import sys
input = sys.stdin.readline

def Recoloring( board ):
	cntW, cntB = 0, 0
	for row in range( 8 ):
		for col in range( 8 ):
			color = board[row][col]
			if ( color is not rightBoards[0][row][col] ):
				cntW += 1
			if ( color is not rightBoards[1][row][col] ):
				cntB += 1

	return min( cntW, cntB )

WB = 'WB' * 4
BW = 'BW' * 4

rightBoards = [ [ WB, BW ] * 4, [ BW, WB ] * 4 ]

board = []
row, col = map( int, input().split() )
for _ in range( row ):
	board.append( input().rstrip() )

minCnt = 25001
for r in range( (row - 8) + 1 ):
	for c in range( (col - 8) + 1 ):
		cutBoard = [ b[c : c + 8] for b in board[r : r + 8] ]

		recol = Recoloring( cutBoard )
		if (  recol < minCnt ):
			minCnt = recol

print( minCnt )
