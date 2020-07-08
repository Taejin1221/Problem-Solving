// Baekjoon10999_SegmentSum2.cpp
// https://www.acmicpc.net/problem/10999
#include <iostream>

#define endl '\n'
#define MAX_ARR_SIZE 1'000'000
#define MAX_TREE_SIZE 4'000'000

using namespace std;

struct TreeNode {
	long val, lazy;
	TreeNode(): val(0), lazy(0) {}
	TreeNode( int v, int l ): val(v), lazy(l) {}
};

struct Range {
	int s, e;
	Range() {}
	Range( int end ): s(0), e(end - 1) {}
	Range( int start, int end ): s(start), e(end) {}
	int getMid() { return ( s + e ) / 2; }
};

Range segment;
long diff;
long arr[MAX_ARR_SIZE];
TreeNode tree[MAX_TREE_SIZE];

void MakeTree( int me, Range range );
long GetSegmentSum( int me, Range range );
void UpdateTree( int me, Range range );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	Range whole = Range( n );
	MakeTree( 1, whole );
	for (int i = 0; i < (m + k); ++i) {
		int opr, s, e;
		cin >> opr >> s >> e;

		segment.s = s - 1; segment.e = e - 1;
		if ( opr == 1 ) {
			cin >> diff;
			UpdateTree( 1, whole );
		} else
			cout << GetSegmentSum( 1, whole ) << endl;

	}

	return 0;
}

void MakeTree( int me, Range range ) {
	if ( range.s == range.e )
		tree[me].val = arr[range.s];
	else {
		int mid = range.getMid();
		int l = me * 2, r = me * 2 + 1;

		MakeTree( l, Range( range.s, mid ) );
		MakeTree( r, Range( mid + 1, range.e ) );

		tree[me].val = tree[l].val + tree[r].val;
	}
}

long GetSegmentSum( int me, Range range ) {
	if ( tree[me].lazy ) {
		if ( range.s != range.e ) {
			tree[me * 2].lazy += tree[me].lazy;
			tree[me * 2 + 1].lazy += tree[me].lazy;
		}

		tree[me].val += (tree[me].lazy * (range.e - range.s + 1) );
		tree[me].lazy = 0;
	}

	if ( range.e < segment.s || segment.e < range.s )
		return 0;
	else if ( segment.s <= range.s && range.e <= segment.e )
		return tree[me].val;
	else {
		int mid = range.getMid();
		int l = me * 2, r = me * 2 + 1;

		return ( GetSegmentSum( l, Range( range.s, mid ) ) + GetSegmentSum( r, Range( mid + 1, range.e ) ) );
	}
}

void UpdateTree( int me, Range range ) {
	if ( tree[me].lazy ) {
		if ( range.s != range.e ) {
			tree[me * 2].lazy += tree[me].lazy;
			tree[me * 2 + 1].lazy += tree[me].lazy;
		}

		tree[me].val += (tree[me].lazy * (range.e - range.s + 1) );
		tree[me].lazy = 0;
	}

	if ( range.e < segment.s || segment.e < range.s )
		return;
	else if ( segment.s <= range.s && range.e <= segment.e ) {
		tree[me].val += ( diff * ( range.e - range.s + 1 ) );
		if ( range.s != range.e ) {
			tree[me * 2].lazy += diff;
			tree[me * 2 + 1].lazy += diff;
		}
		tree[me].lazy = 0;
	}
	else {
		int mid = range.getMid();
		int l = me * 2, r = me * 2 + 1;

		UpdateTree( l, Range( range.s, mid ) );
		UpdateTree( r, Range( mid + 1, range.e ) );

		tree[me].val = tree[l].val + tree[r].val;
	}
}
