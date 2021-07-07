// Baekjoon12844_XOR.cpp
// https://www.acmicpc.net/problem/12844
#include <iostream>

#define endl '\n'
#define MAX_ARR_SIZE 500'000
#define MAX_TREE_SIZE 2'000'000

using namespace std;

struct Range {
	int start, end;
	Range() {}
	Range( int e ): start(0), end(e - 1) {}
	Range( int s, int e): start(s), end(e) {}
	int getMid();
	bool isLeaf();
};

struct TreeNode {
	int val, lazy;
	TreeNode(): val(0), lazy(0) {}
	TreeNode( int val, int lazy): val(val), lazy(lazy) {}
};

int targetVal;
Range segment;
int arr[MAX_ARR_SIZE];
TreeNode tree[MAX_TREE_SIZE];

void MakeTree( int me, Range range );
void Propagate( int me, Range range );
void UpdateTree( int me, Range range );
int GetSegmentXOR( int me, Range range );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	Range whole = Range( n );
	MakeTree( 1, whole );

	int m; cin >> m;
	while ( m-- ) {
		int opr;
		cin >> opr;

		if ( opr == 1 ) {
			cin >> segment.start >> segment.end >> targetVal;

			UpdateTree( 1, whole );
		} else {
			cin >> segment.start >> segment.end;

			cout << GetSegmentXOR( 1, whole ) << endl;
		}
	}

	return 0;
}

// Function
void MakeTree( int me, Range range ) {
	if ( range.isLeaf() )
		tree[me].val = arr[range.start];
	else {
		int mid = range.getMid();
		int left = me * 2, right = me * 2 + 1;

		MakeTree( left, Range( range.start, mid ) );
		MakeTree( right, Range( mid + 1, range.end ) );

		tree[me].val = tree[left].val ^ tree[right].val;
	}
}

void Propagate( int me, Range range ) {
	if ( tree[me].lazy ) {
		if ( range.isLeaf() )
			tree[me].val ^= tree[me].lazy;
		else {
			if ( (range.end - range.start) % 2 == 0 ) // if range is odd
				tree[me].val ^= tree[me].lazy;
			tree[me * 2].lazy ^= tree[me].lazy;
			tree[me * 2 + 1].lazy ^= tree[me].lazy;
		}

		tree[me].lazy = 0;
	}
}

void UpdateTree( int me, Range range ) {
	Propagate( me, range );
	if ( range.end < segment.start || segment.end < range.start )
		return;
	else if ( segment.start <= range.start && range.end <= segment.end ) {
		if ( range.isLeaf() )
			tree[me].val ^= targetVal;
		else {
			if ( (range.end - range.start) % 2 == 0 )
				tree[me].val ^= targetVal;
			tree[me * 2].lazy ^= targetVal;
			tree[me * 2 + 1].lazy ^= targetVal;
		}
	} else {
		int mid = range.getMid();
		int left = me * 2, right = me * 2 + 1;

		UpdateTree( left, Range( range.start, mid ) );
		UpdateTree( right, Range( mid + 1, range.end ) );

		tree[me].val = tree[left].val ^ tree[right].val;
	}
}

int GetSegmentXOR( int me, Range range ) {
	Propagate( me, range );
	if ( range.end < segment.start || segment.end < range.start )
		return 0;
	else if ( (segment.start <= range.start) && (range.end <= segment.end) ) {
		return tree[me].val;
	} else {
		int mid = range.getMid();
		int left = me * 2, right = me * 2 + 1;

		int leftVal = GetSegmentXOR( left, Range( range.start, mid ) );
		int rightVal = GetSegmentXOR( right, Range( mid + 1, range.end ) );

		return leftVal ^ rightVal;
	}
}

// Method
int Range::getMid() {
	return ( start + end ) / 2;
}

bool Range::isLeaf() {
	return start == end;
}