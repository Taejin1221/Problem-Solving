// Baekjoon02580_Sudoku.cpp
// https://www.acmicpc.net/problem/2580
#include <iostream>
#include <vector>

using namespace std;

struct Position {
	int row, col;
	Position( int x, int y ) : row(x), col(y) {}
};

int board[9][9];
vector<Position> zeros;

bool isValid( Position curr);
bool FillSudoku( Position curr, int idx );

int main(void) {
	ios_base::sync_with_stdio( false );
	cin.tie( NULL );
	cout.tie( NULL );

	for ( int i = 0; i < 9; i++ )
		for ( int j = 0; j < 9; j++ )
			cin >> board[i][j];

	for ( int i = 0; i < 9; i++ )
		for ( int j = 0; j < 9; j++ )
			if ( board[i][j] == 0 )
				zeros.push_back( Position(i, j) );

	FillSudoku( zeros[0], 1 );
	for ( int i = 0; i < 9; i++ ) {
		for ( int j = 0; j < 9; j++ )
			cout << board[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}

bool isValid( int currVal, Position curr ) {
	// Check row and column;
	for ( int i = 0; i < 9; i++ ) {
		if ( curr.row != i && board[i][curr.col] == currVal )
			return false;

		if ( curr.col != i && board[curr.row][i] == currVal )
			return false;
	}

	// Check 3x3
	Position center = Position( curr.row - ( curr.row % 3 ) + 1, curr.col - ( curr.col % 3 ) + 1 );
	for ( int r = center.row - 1; r < center.row + 2; r++ )
		for ( int c = center.col - 1; c < center.col + 2; c++ )
			if ( ( r != curr.row || c != curr.col ) && board[r][c] == currVal )
				return false;

	return true;
}

bool FillSudoku( Position curr, int idx ) {
	if ( idx == zeros.size() ) {
		for ( int i = 1; i < 10; i++ )
			if ( isValid( i, curr ) ) {
				board[curr.row][curr.col] = i;
				return true;
			}
		return false;
	} else {
		for ( int i = 1; i < 10; i++ )
			if ( isValid( i, curr ) ) {
				board[curr.row][curr.col] = i;
				if ( FillSudoku( zeros[idx], idx + 1 ) )
					return true;
				else
					board[curr.row][curr.col] = 0;
			}
		return false;
	}
}
