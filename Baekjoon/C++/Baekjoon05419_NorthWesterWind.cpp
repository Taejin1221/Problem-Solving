// Baekjoon05419_NorthWesterWind.cpp
// https://www.acmicpc.net/problem/5419
#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

typedef vector<int>::iterator viter;

struct Coordinate {
	int x, y;
	Coordinate() {}
	Coordinate( int x, int y ): x(x), y(y) {}
	bool operator<( const Coordinate& c2 );
};

struct Range {
	int start, end;
	Range() {}
	Range( int s, int e ): start(s), end(e) {}
	int getMid();
	void update( int s, int e );
};

int startIdx;
Range segment;

long GetUpperFromTree( vector<long>& tree, int me, Range range );
void UpdateTree( vector<long>& tree, int me, Range range );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int time;
	cin >> time;
	while ( time-- ) {
		int n;
		cin >> n;

		vector<int> yCoords;
		vector<Coordinate> coords;
		for ( int i = 0; i < n; i++ ) {
			int x, y;
			cin >> x >> y;

			coords.push_back( Coordinate( x, y ) );
			yCoords.push_back( y );
		}
		sort( coords.begin(), coords.end() );
		sort( yCoords.begin(), yCoords.end() );
		yCoords.erase( unique( yCoords.begin(), yCoords.end() ), yCoords.end() );

		int ySize = yCoords.size();
		vector<long> tree ( 4 * ySize, 0 );
		Range whole = Range( 0, ySize - 1 );

		long island = 0;
		for ( int i = 0; i < n; i++ ) {
			Coordinate& curr = coords[i];

			startIdx = lower_bound( yCoords.begin(), yCoords.end(), curr.y ) - yCoords.begin();

			segment.update( startIdx, ySize - 1 );
			island += GetUpperFromTree( tree, 1, whole );

			UpdateTree( tree, 1, whole );
		}

		cout << island << endl;
	}

	return 0;
}

// Function
long GetUpperFromTree( vector<long>& tree, int me, Range range ) {
	if ( range.end < segment.start || segment.end < range.start )
		return 0;
	else if ( segment.start <= range.start && range.end <= segment.end )
		return tree[me];
	else {
		int mid = range.getMid();
		int left = me * 2, right = me * 2 + 1;

		long leftSum = GetUpperFromTree( tree, left, Range( range.start, mid ) );
		long rightSum = GetUpperFromTree( tree, right, Range( mid + 1, range.end ) );

		return ( leftSum + rightSum );
	}
}

void UpdateTree( vector<long>& tree, int me, Range range ) {
	if ( range.end < startIdx || startIdx < range.start )
		return;

	if ( range.start != range.end ) {
		int mid = range.getMid();
		int left = me * 2, right = me * 2 + 1;
	
		UpdateTree( tree, left, Range( range.start, mid ) );
		UpdateTree( tree, right, Range( mid + 1, range.end ) );

		tree[me] = tree[left] + tree[right];
	} else if ( range.start == startIdx )
		tree[me]++;
}

// Method
bool Coordinate::operator<( const Coordinate& c2 ) {
	if ( x != c2.x )
		return x < c2.x;
	else
		return y > c2.y;
}

int Range::getMid() {
	return ( start + end ) / 2;
}

void Range::update( int s, int e ) {
	this->start = s;
	this->end = e;
}