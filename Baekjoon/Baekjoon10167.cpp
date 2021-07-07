// Baekjoon10167_GoldMine.cpp
// https://www.acmicpc.net/problem/10167
#include <iostream>
#include <algorithm> /* sort(), lower_bound() */
#include <vector>

#define endl '\n'
#define MAX_ARR_SIZE 3'000
#define MAX_TREE_SIZE 12'000

using namespace std;

typedef long long ll;

struct Coordinate {
	int x, y, w;
	Coordinate() {}
	Coordinate( int x, int y, int w ): x(x), y(y), w(w) {}
	bool operator<( const Coordinate& c2 );
};

struct TreeNode {
	ll sum, total, leftMax, rightMax;
	TreeNode(): sum(0), total(0), leftMax(0), rightMax(0) {}
	void init();
};

struct Range {
	int start, end;
	Range() {}
	Range( int e ): start(0), end( e - 1 ) {}
	Range( int s, int e ): start(s), end(e) {}
	int getMid();
};

ll targetVal;
int targetIdx;
TreeNode tree[MAX_TREE_SIZE];

void UpdateTree( int me, Range range );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> yCoords;
	Coordinate coords[MAX_ARR_SIZE];
	for ( int i = 0; i < n; i++ ) {
		cin >> coords[i].x >> coords[i].y >> coords[i].w;
		yCoords.push_back( coords[i].y );
	}
	sort( coords, coords + n );
	sort( yCoords.begin(), yCoords.end() );

	yCoords.erase( unique( yCoords.begin(), yCoords.end() ), yCoords.end() );

	int ySize = yCoords.size();
	Range whole = Range( ySize );

	ll maxProfit = 0;
	for ( int i = 0; i < n; i++ ) {
		if ( i > 0 && coords[i].x == coords[i - 1].x )
			continue;
		
		for ( int j = 0; j < MAX_TREE_SIZE; j++ )
			tree[j].init();

		for ( int j = i; j < n; j++ ) {
			while (true) {
				targetVal = coords[j].w;
				targetIdx = lower_bound( yCoords.begin(), yCoords.end(), coords[j].y ) - yCoords.begin();

				UpdateTree( 1, whole );
				if ( j + 1 < n && coords[j].x == coords[j + 1].x )
					j++;
				else
					break;
			}

			maxProfit = max(maxProfit, tree[1].total);
		}
	}

	cout << maxProfit << endl;

	return 0;
}

// Function
ll max( ll a, ll b, ll c ) {
	if ( a >= b && a >= c )
		return a;
	else if ( b >= a && b >= c )
		return b;
	else
		return c;
}

void UpdateTree( int me, Range range ) {
	if ( targetIdx < range.start || range.end < targetIdx )
		return;

	if ( range.start != range.end ) {
		int mid = range.getMid();
		int left = me * 2, right = me * 2 + 1;

		UpdateTree( left, Range( range.start, mid ) );
		UpdateTree( right, Range( mid + 1, range.end ) );

		tree[me].sum = tree[left].sum + tree[right].sum;
		tree[me].total = max( tree[left].total, tree[right].total, tree[left].rightMax + tree[right].leftMax );
		tree[me].leftMax = max( tree[left].leftMax, tree[left].sum + tree[right].leftMax );
		tree[me].rightMax = max( tree[right].rightMax, tree[left].rightMax + tree[right].sum );
	} else if ( range.start == targetIdx ) {
		tree[me].sum += targetVal;
		tree[me].total += targetVal;
		tree[me].leftMax += targetVal;
		tree[me].rightMax += targetVal;
	}
}

// Method
bool Coordinate::operator<( const Coordinate& c2 ) {
	if ( x != c2.x )
		return x < c2.x;
	else
		return y < c2.y;
}

void TreeNode::init() {
	sum = 0LL;
	total = 0LL;
	leftMax = 0LL, rightMax = 0LL;
}

int Range::getMid() {
	return ( start + end ) / 2;
}