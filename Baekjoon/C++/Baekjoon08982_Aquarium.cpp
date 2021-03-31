// Baekjoon08982_Aquarium.cpp
// https://www.acmicpc.net/problem/8982
#include <iostream>

#include <vector>

using namespace std;

struct Coordinate {
	int row, col;
	Coordinate( ): row( 0 ), col( 0 ) { }
	Coordinate( int r, int c ): row( r ), col( c ) { }
};

struct Hole {
	int row, col1, col2;
	Hole( ): row( 0 ), col1( 0 ), col2( 0 ) { }
	Hole( int r, int c1, int c2 ): row( r ), col1( c1 ), col2( c2 ) { }
	bool operator==( const Hole& h2 ) {
		return ( row == h2.row && col1 == h2.col1 && col2 == h2.col2 );
	}
};

int getArea( vector<Coordinate>& boundaries );
int DrainWater( vector<Coordinate>& boundaries, vector<Hole>& holes );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<Coordinate> boundaries ( n );
	for ( int i = 0; i < n; i++ )
		cin >> boundaries[i].col >> boundaries[i].row;

	int m;
	cin >> m;

	vector<Hole> holes ( m );
	for ( int i = 0; i < m; i++ )
		cin >> holes[i].col1 >> holes[i].row >> holes[i].col2 >> holes[i].row;

	int area = getArea( boundaries );
	area -= DrainWater( boundaries, holes );

	cout << area << '\n';

	return 0;
}

int getArea( vector<Coordinate>& boundaries ) {
	int area = 0;
	for ( int i = 1; i < boundaries.size() - 1; i += 2 )
		area += (boundaries[i + 1].col - boundaries[i].col) * ( boundaries[i].row - 0 );

	return area;
}

int DrainWater( vector<Coordinate>& boundaries, vector<Hole>& holes ) {
	if ( holes.size() == 0 )
		return 0;
	else {
		int n = boundaries.size(), m = holes.size();

		int topBoundaryIdx = 1;
		for ( int i = 1; i < n - 1; i += 2 )
			if ( boundaries[i].row < boundaries[topBoundaryIdx].row )
				topBoundaryIdx = i;

		Coordinate& topBoundary = boundaries[topBoundaryIdx];
		int drain = (topBoundary.row - boundaries[0].row) * (boundaries[n - 1].col - boundaries[0].col);

		vector<Coordinate> leftBoundaries, rightBoundaries;
		for ( int i = 0; i <= topBoundaryIdx; i++ ) {
			if ( boundaries[i].row < topBoundary.row )
				leftBoundaries.push_back( Coordinate( topBoundary.row, boundaries[i].col ) );
			else
				leftBoundaries.push_back( boundaries[i] );
		}

		for ( int i = topBoundaryIdx + 1; i < n; i++ ) {
			if ( boundaries[i].row < topBoundary.row )
				rightBoundaries.push_back( Coordinate( topBoundary.row, boundaries[i].col ) );
			else
				rightBoundaries.push_back( boundaries[i] );
		}

		Hole topHole = Hole( topBoundary.row, topBoundary.col, boundaries[topBoundaryIdx + 1].col );
		vector<Hole> leftHoles, rightHoles;
		for ( int i = 0; i < m; i++ ) {
			if ( !(topHole == holes[i]) ) {
				if ( holes[i].col1 < topHole.col1 )
					leftHoles.push_back( holes[i] );
				else
					rightHoles.push_back( holes[i] );
			}
		}

		drain += ( DrainWater( leftBoundaries, leftHoles ) + DrainWater( rightBoundaries, rightHoles ) );

		return drain;
	}
}
