// Baekjoon17387_LineIntersection2.cpp
// https://www.acmicpc.net/problem/17387
#include <iostream>

using namespace std;

struct Coordinate {
	long x, y;
	Coordinate(): x(0), y(0) {}
	Coordinate( long x, long y ): x(x), y(y) {}
	bool operator<( Coordinate coords2 ) {
		if ( x != coords2.x )
			return x < coords2.x;
		else
			return y < coords2.y;
	}

	bool operator<=( Coordinate coords2 ) {
		if ( x != coords2.x )
			return x <= coords2.x;
		else
			return y <= coords2.y;
	}
};

int CCW( Coordinate pos1, Coordinate pos2, Coordinate pos3 );
bool isLineIntersect( Coordinate line1[], Coordinate line2[] );

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

	if ( lines[1][0] < lines[0][0] ) {
		Coordinate temp = lines[0][0];
		lines[0][0] = lines[1][0];
		lines[1][0] = temp;

		temp = lines[0][1];
		lines[0][1] = lines[1][1];
		lines[1][1] = temp;
	}

	if ( isLineIntersect( lines[0], lines[1] ) )
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

bool isLineIntersect( Coordinate line1[], Coordinate line2[] ) {
	int inter1 = CCW( line1[0], line1[1], line2[0] ) * CCW( line1[0], line1[1], line2[1] );
	int inter2 = CCW( line2[0], line2[1], line1[0] ) * CCW( line2[0], line2[1], line1[1] );

	if ( inter1 == 0 && inter2 == 0 ) {
		if ( ( (line1[0] < line2[1]) && (line1[1] < line2[0]) ) )
			return false;
		else
			return true;
	}
	else if ( inter1 <= 0 && inter2 <= 0 )
		return true;
	else
		return false;
}