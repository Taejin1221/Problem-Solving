// Baekjoon01063_King.cpp
// https://www.acmicpc.net/problem/1063
#include <iostream>

#include <cstring>

using namespace std;

struct Coordinate {
	int row;
	char col;
	Coordinate( ): row( 0 ), col( 0 ) { }
	Coordinate( int r, char c ): row( r ), col( c ) { }
	Coordinate move( char dir[] );
	bool operator==( const Coordinate& c2 ) const {
		return row == c2.row && col == c2.col;
	}
	bool isValid( ) {
		return ( ( 1 <= row && row <= 8 ) && ( 'A' <= col && col <= 'H' ) );
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	Coordinate king, stone;

	char temp[3];
	cin >> temp;
	king.col = temp[0];
	king.row = temp[1] - '0';

	cin >> temp;
	stone.col = temp[0];
	stone.row = temp[1] - '0';

	cin >> n;
	while ( n-- ) {
		cin >> temp;

		Coordinate tempKing = king.move( temp );
		if ( tempKing == stone ) {
			Coordinate tempStone = stone.move( temp );
			if ( tempStone.isValid() )
				king = tempKing, stone = tempStone;
		} else {
			if ( tempKing.isValid() )
				king = tempKing;
		}
	}

	cout << king.col << king.row << '\n';
	cout << stone.col << stone.row << '\n';

	return 0;
}

Coordinate Coordinate::move( char dir[] ) {
	if ( !strcmp( dir, "R" ) )
		return Coordinate( row, col + 1 );
	else if ( !strcmp( dir, "L" ) )
		return Coordinate( row, col - 1 );
	else if ( !strcmp( dir, "B" ) )
		return Coordinate( row - 1, col );
	else if ( !strcmp( dir, "T" ) )
		return Coordinate( row + 1, col );
	else if ( !strcmp( dir, "RT" ) )
		return Coordinate( row + 1, col + 1 );
	else if ( !strcmp( dir, "LT" ) )
		return Coordinate( row + 1, col - 1 );
	else if ( !strcmp( dir, "RB" ) )
		return Coordinate( row - 1, col + 1 );
	else if ( !strcmp( dir, "LB" ) )
		return Coordinate( row - 1, col - 1 );
}