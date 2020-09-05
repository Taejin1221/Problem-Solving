// Baekjoon14500_Tetromino.cpp
// https://www.acmicpc.net/problem/14500
#include <iostream>

using namespace std;

struct Position {
	int row, col;
	Position( ): row(0), col(0) {};
	Position( int r, int c ): row(r), col(c) {};
	bool operator!=( const Position& p2 ) const {
		return ( this->row != p2.row || this->col != p2.col );
	}
};

int maxVal, maxRow, maxCol;
int table[500][500];

void dfs( Position curr, Position prev, int size, int sum );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> maxRow >> maxCol;

	for ( int i = 0; i < maxRow; i++ )
		for ( int j = 0; j < maxCol; j++ )
			cin >> table[i][j];

	for ( int i = 0; i < maxRow; i++ )
		for ( int j = 0; j < maxCol; j++ )
			dfs( Position( i, j ), Position( -1, -1 ), 0, 0 );

	cout << maxVal << '\n';

	return 0;
}

void dfs( Position curr, Position prev, int size, int sum ) {
	if ( size == 4 )
		maxVal = max( maxVal, sum );
	else {
		Position nexts[4] = {
			Position( curr.row - 1, curr.col ),
			Position( curr.row, curr.col + 1 ),
			Position( curr.row + 1, curr.col ),
			Position( curr.row, curr.col - 1 )
		};

		for ( Position& next : nexts )
			if ( next != prev )
				if ( ( 0 <= next.row && next.row < maxRow ) && ( 0 <= next.col && next.col < maxCol ) )
					dfs( next, curr, size + 1, sum + table[next.row][next.col] );
	}
}