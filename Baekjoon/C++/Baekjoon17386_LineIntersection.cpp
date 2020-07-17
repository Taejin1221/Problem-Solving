// Baekjoon17386_LineIntersection.cpp
// https://www.acmicpc.net/problem/17386
#include <iostream>

using namespace std;

struct Coordinate {
	long x, y;
	Coordinate(): x(0), y(0) {}
	Coordinate( long x, long y ): x(x), y(y) {}
	bool operator<=( Coordinate coords2 ) {
		if ( x != coords2.x )
			return x <= coords2.x;
		else
			return y <= coords2.y;
	}
};

int CCW( Coordinate pos1, Coordinate pos2, Coordinate pos3 );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Coordinate lines[2][2];
	for ( int i = 0; i < 2; i++ ) {
		Coordinate coords1, coords2;
		cin >> coords1.x >> coords1.y;
		cin >> coords2.x >> coords2.y;

		if ( coords1 <= coords2 ) {
			lines[i][0] = coords1;
			lines[i][1] = coords2;
		} else {
			lines[i][0] = coords2;
			lines[i][1] = coords1;
		}
	}

	int inter1 = CCW( lines[0][0], lines[0][1], lines[1][0] ) * CCW( lines[0][0], lines[0][1], lines[1][1] );
	int inter2 = CCW( lines[1][0], lines[1][1], lines[0][0] ) * CCW( lines[1][0], lines[1][1], lines[0][1] );

	if ( inter1 == 0 && inter2 == 0 ) {
		if ( lines[0][0] <= lines[1][1] && lines[0][1] <= lines[1][0] )
			cout << 0;
		else
			cout << 1;

	}
	else if ( inter1 <= 0 && inter2 <= 0 )
		cout << 1;
	else
		cout << 0;
	cout << '\n';

	return 0;
}

int CCW( Coordinate pos1, Coordinate pos2, Coordinate pos3 ) {
	long dir = ( pos2.x - pos1.x ) * ( pos3.y - pos1.y );
	dir -= ( pos3.x - pos1.x ) * ( pos2.y - pos1.y );

	if ( dir ) {
		if ( dir > 0 )
			return 1;
		else
			return -1;
	} else
		return 0;
}