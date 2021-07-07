// Baekjoon03392_MarsMap.cpp
// https://www.acmicpc.net/problem/3392
#include <iostream>
#include <vector>
#include <algorithm> /* sort() */

#define endl '\n'
#define MAX_Y_RANGE 30'000
#define MAX_TREE_SIZE 120'000

using namespace std;

struct Line {
	int x, top, bottom;
	bool isStart;
	Line() {}
	Line( int x, int t, int b, bool s ): x(x), top(t), bottom(b), isStart(s) {}
	bool operator<( const Line& line2 );
};

struct Range {
	int start, end;
	Range(): start(0), end(0) {}
	Range( int s, int e ): start(s), end(e) {}
	int getMid();
	void update( const Line& l1 );
};

Range segment;
int tree[MAX_TREE_SIZE];
int countTree[MAX_TREE_SIZE];

void UpdateTree( int me, bool isStart, Range range );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Line> lines;
	for ( int i = 0; i < n; i++ ) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		lines.push_back( Line( x1, y2 - 1, y1, true ) );
		lines.push_back( Line( x2, y2 - 1, y1, false ) );
	}
	sort( lines.begin(), lines.end() );

	Range whole = Range( 0, MAX_Y_RANGE );
	segment.update( lines[0] );
	UpdateTree( 1, true, whole );

	int prevX = lines[0].x, area = 0;
	for ( int i = 1; i < (n * 2); i++ ) {
		area += tree[1] * ( lines[i].x - prevX );
		prevX = lines[i].x;

		segment.update( lines[i] );
		UpdateTree( 1, lines[i].isStart, whole );
	}

	cout << area << endl;

	return 0;
}

// Function
void UpdateTree( int me, bool isStart, Range range ) {
	if ( range.end < segment.start || segment.end < range.start )
		return;
	else if ( segment.start <= range.start && range.end <= segment.end )
		countTree[me] += ( isStart ) ? 1 : -1;
	else {
		int mid = range.getMid();
		int left = me * 2, right = me * 2 + 1;

		UpdateTree( left, isStart, Range( range.start, mid ) );
		UpdateTree( right, isStart, Range( mid + 1, range.end ) );
	}

	if ( countTree[me] )
		tree[me] = ( range.end - range.start + 1 );
	else {
		if ( range.start == range.end )
			tree[me] = 0;
		else
			tree[me] = tree[me * 2] + tree[me * 2 + 1];
	}
}

// Method
int Range::getMid() {
	return ( start + end ) / 2;
}

void Range::update( const Line& l1 ) {
	start = l1.bottom;
	end = l1.top;
}

bool Line::operator<( const Line& line2 ) {
	return ( x < line2.x );
}
