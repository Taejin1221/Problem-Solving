// Baekjoon02239_Sudoku.cpp
// https://www.acmicpc.net/problem/2239
#include <iostream>
#include <vector>

using namespace std;

char board[9][10];
vector<pair<int, int>> zeroes;

bool isValid( int row, int col, int num );
bool SolveSudoku( int zeroNum );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for ( int i = 0; i < 9; i++ ) {
		cin >> board[i];
		for ( int j = 0; j < 9; j++ )
			if ( board[i][j] == '0' )
				zeroes.push_back( make_pair( i, j ) );
	}

	SolveSudoku( 0 );

	for ( int i = 0; i < 9; i++ )
		cout << board[i] << '\n';

	return 0;
}

bool isValid( int row, int col, int num ) {
	for ( int i = 0; i < 9; i++ )
		if ( board[row][i] == num + '0' )
			return false;

	for ( int i = 0; i < 9; i++ )
		if ( board[i][col] == num + '0' )
			return false;

	int startRow = row - ( row % 3 ), startCol = col - ( col % 3 );
	for ( int i = 0; i < 3; i++ )
		for ( int j = 0; j < 3; j++ )
			if ( board[startRow + i][startCol + j] == num + '0' )
				return false;

	return true;
}

bool SolveSudoku( int zeroNum ) {
	if ( zeroNum == zeroes.size() )
		return true;
	else {
		int row = zeroes[zeroNum].first, col = zeroes[zeroNum].second;
		for ( int i = 1; i < 10; i++ ) {
			if ( isValid( row, col, i ) ) {
				board[row][col] = i + '0';
				if ( SolveSudoku( zeroNum + 1 ) )
					return true;
				board[row][col] = '0';
			}
		}

		return false;
	}
}