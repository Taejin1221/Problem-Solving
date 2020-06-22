# LeetCode0051_N-Queens.py
class Solution:
	def solveNQueens( self, N: int ) -> List[List[str]]:
		nqueens = []

		def isValid( queens, x, y ):
			for q in queens:
				if ( (q[1] == y) or (q[0] - q[1] == x - y)
					or (q[0] + q[1] == x + y) ):
					return False

			return True

		def nqueen( size, queens ):
			if size == N:
				board = [ ]
				for i in range( N ):
					row = ''
					for j in range( N ):
						if ( i, j ) in queens:
							row += 'Q'
						else:
							row += '.'
					board.append( row )
				nqueens.append( board )
			else:
				for j in range( N ):
					if isValid( queens, size, j ):
						nqueen( size + 1, queens + [ (size, j) ] )

		for j in range( N ):
			nqueen( 1, [ ( 0, j ) ] )

		return nqueens
