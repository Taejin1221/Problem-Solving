// Baekjoon01708_ConvexHull.cpp
// https://www.acmicpc.net/problem/1708
#include <iostream>
#include <algorithm> /* sort() */
#include <stack>

#define endl '\n'
#define MAX_ARR_SIZE 100'000

using namespace std;

struct Coordinate {
	int x, y;
	int disX, disY;
	Coordinate(): x(0), y(0), disX(1), disY(0) {}
	Coordinate( int x, int y ): x(x), y(y), disX(1), disY(0) {}
	bool operator<( const Coordinate& coord2 );
};

int CCW( Coordinate co1, Coordinate co2, Coordinate co3 );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	Coordinate coords[MAX_ARR_SIZE];
	for ( int i = 0; i < n; i++ )
		cin >> coords[i].x >> coords[i].y;
	sort( coords, coords + n );

	for ( int i = 1; i < n; i++ ) {
		coords[i].disX = coords[i].x - coords[0].x;
		coords[i].disY = coords[i].y - coords[0].y;
	}
	sort( coords + 1, coords + n );

	stack<int> stck;
	stck.push( 0 ); stck.push( 1 );

	for ( int nextIdx = 2; nextIdx < n; nextIdx++ ) {
		while ( stck.size() >= 2 ) {
			int prev1, prev2;
			prev1 = stck.top(); stck.pop();
			prev2 = stck.top();

			if ( CCW( coords[prev2], coords[prev1], coords[nextIdx] ) > 0 ) {
				stck.push( prev1 );
				break;
			}
		}

		stck.push( nextIdx );
	}

	cout << stck.size() << endl;

	return 0;
}

// Function
int CCW( Coordinate co1, Coordinate co2, Coordinate co3 ) {
	long dir = (long)( co2.x - co1.x ) * ( co3.y - co1.y );
	dir -= (long)( co3.x - co1.x ) * ( co2.y - co1.y );

	if ( dir ) {
		if ( dir > 0 )
			return 1;
		else
			return -1;
	} else
		return 0;
}

// Method
bool Coordinate::operator<( const Coordinate& coord2 ) {
	if ( 1LL * disY * coord2.disX != 1LL * coord2.disY * disX )
		return ( 1LL * disY * coord2.disX < 1LL * coord2.disY * disX );
	else if ( y != coord2.y )
		return y < coord2.y;
	else
		return x < coord2.x;
}