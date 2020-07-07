// Baekjoon02261_NearestPoints.cpp
// https://www.acmicpc.net/problem/2261
#include <iostream>
#include <algorithm> /* sort() */
#include <cmath> /* sqrt() */
#include <set>

using namespace std;

struct Coordinate {
	int x, y;
	Coordinate() {}
	Coordinate( int xPos, int yPos ): x(xPos), y(yPos) {}
	bool operator<( const Coordinate& c2 ) const;
};
typedef set<Coordinate>::iterator it;

bool Compare( const Coordinate& c1, const Coordinate& c2 );
int getDistance( const Coordinate& c1, const Coordinate& c2 );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	Coordinate coords[100'000];
	for ( int i = 0; i < n; i++ ) {
		int x, y;
		cin >> x >> y;

		coords[i].x = x;
		coords[i].y = y;
	}
	sort( coords, coords + n, Compare );

	int boundIdx = 0;
	set<Coordinate> s = { coords[0], coords[1] };
	int dis = getDistance( coords[0], coords[1] );
	for ( int i = 2; i < n; i++ ) {
		Coordinate curr = coords[i];

		int boundX = coords[boundIdx].x - curr.x;
		while ( (boundIdx < i) && (boundX * boundX) > dis ) {
			s.erase( coords[boundIdx++] );
			boundX = coords[boundIdx].x - curr.x;
		}

		int d = (int)sqrt(dis) + 1;
		it lower = s.lower_bound( Coordinate( -100'000, curr.y - d ) );
		it upper = s.upper_bound( Coordinate( 100'000, curr.y + d ) );

		for ( it iter = lower; iter != upper; iter++ ) {
			int currDis = getDistance( curr, *iter );
			dis = ( dis > currDis ) ? currDis : dis;
		}

		s.insert( curr );
	}

	cout << dis << '\n';

	return 0;
}

bool Coordinate::operator<( const Coordinate& c2 ) const {
	if ( y != c2.y )
		return y < c2.y;
	else
		return x < c2.x;
}

bool Compare( const Coordinate& c1, const Coordinate& c2 ) {
	if ( c1.x != c2.x )
		return c1.x < c2.x;
	else
		return c1.y < c2.y;
}

int getDistance( const Coordinate& c1, const Coordinate& c2 ) {
	int xDis = c1.x - c2.x, yDis = c1.y - c2.y;
	return ( xDis * xDis + yDis * yDis );
}
