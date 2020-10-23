// Baekjoon16975_SequenceAndQuery21.cpp
// https://www.acmicpc.net/problem/16975
#include <iostream>

#define endl '\n'
#define MAX_ARR_SIZE 100'000
#define MAX_TREE_SIZE 400'000

using namespace std;

struct TreeNode {
	long long val, lazy;
	TreeNode(): val(0), lazy(0) { }
};

struct Range {
	int start, end;
	Range( int s, int e ): start(s), end(e) { }
	int getMid() {
		return ( start + end ) / 2;
	}
};

int arr[MAX_ARR_SIZE];
TreeNode tree[MAX_TREE_SIZE];

void MakeTree( int me, Range curr );
long long GetValue( int me, Range curr, int& idx );
void UpdateSegment( int me, Range curr, Range& segment, long long& value );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	Range wholeRange = Range( 0, n - 1 );
	MakeTree( 1, wholeRange );

	int q;
	cin >> q;
	while ( q-- ) {
		int query;
		cin >> query;

		if ( query == 1 ) {
			int i, j;
			long long k;
			cin >> i >> j >> k;

			Range segment = Range( i - 1, j - 1 );
			UpdateSegment( 1, wholeRange, segment, k );
		} else {
			int x;
			cin >> x;

			x--;
			cout << GetValue( 1, wholeRange, x ) << endl;
		}
	}

	return 0;
}

void MakeTree( int me, Range curr ) {
	if ( curr.start == curr.end )
		tree[me].val = arr[curr.start];
	else {
		int mid = curr.getMid();
		int left = me * 2, right = me * 2 + 1;

		MakeTree( left, Range( curr.start, mid ) );
		MakeTree( right, Range( mid + 1, curr.end ) );

		tree[me].val = tree[left].val + tree[right].val;
	}
}

long long GetValue( int me, Range curr, int& idx ) {
	if ( tree[me].lazy ) {
		if ( curr.start != curr.end ) {
			tree[me * 2].lazy += tree[me].lazy;
			tree[me * 2 + 1].lazy += tree[me].lazy;
		}
		tree[me].val += tree[me].lazy * ( curr.end - curr.start + 1);
		tree[me].lazy = 0;
	}

	if ( idx < curr.start || curr.end < idx )
		return 0;
	else if ( curr.start == curr.end && curr.start == idx )
		return tree[me].val;
	else {
		int mid = curr.getMid();
		int left = me * 2, right = me * 2 + 1;

		return (
			GetValue( left, Range( curr.start, mid ), idx ) +
			GetValue( right, Range( mid + 1, curr.end ), idx )
		);
	}
}

void UpdateSegment( int me, Range curr, Range& segment, long long& value ) {
	if ( tree[me].lazy ) {
		if ( curr.start != curr.end ) {
			tree[me * 2].lazy += tree[me].lazy;
			tree[me * 2 + 1].lazy += tree[me].lazy;
		}

		tree[me].val += tree[me].lazy * ( curr.end - curr.start + 1);
		tree[me].lazy = 0;
	}

	if ( segment.end < curr.start || curr.end < segment.start )
		return;
	else if ( segment.start <= curr.start && curr.end <= segment.end ) {
		tree[me].val += value * ( curr.end - curr.start + 1);
		if ( curr.start != curr.end ) {
			tree[me * 2].lazy += value;
			tree[me * 2 + 1].lazy += value;
		}
	} else {
		int mid = curr.getMid();
		int left = me * 2, right = me * 2 + 1;
		UpdateSegment( left, Range( curr.start, mid ), segment, value );
		UpdateSegment( right, Range( mid + 1, curr.end ), segment, value );

		tree[me].val = tree[left].val + tree[right].val;
	}
}
