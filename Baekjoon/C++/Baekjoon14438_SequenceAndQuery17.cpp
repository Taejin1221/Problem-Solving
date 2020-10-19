// Baekjoon14438_SequenceAndQuery17.cpp
// https://www.acmicpc.net/problem/14438
#include <iostream>

#define endl '\n'
#define MAX 1'000'000'001
#define MAX_ARR_SIZE 100'000
#define MAX_TREE_SIZE 400'000

using namespace std;

struct Range {
	int start, end;
	Range(int s, int e): start(s), end(e) { }
	int getMid() {
		return (start + end) / 2;
	}
};

int arr[MAX_ARR_SIZE];
int tree[MAX_TREE_SIZE];

void MakeTree( int me, Range curr );
int GetMinValue( int me, Range curr, Range& segment );
void UpdateTree( int me, Range curr, int& idx, int& value );

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
		int a, b, c;
		cin >> a >> b >> c;
		if ( a == 1 ) {
			b--;
			UpdateTree( 1, wholeRange, b, c );
		} else {
			Range segment = Range( b - 1, c - 1 );
			cout << GetMinValue( 1, wholeRange, segment ) << endl;
		}
	}

	return 0;
}

void MakeTree( int me, Range curr ) {
	if ( curr.start == curr.end )
		tree[me] = arr[curr.start];
	else {
		int mid = curr.getMid();
		int left = me * 2, right = me * 2 + 1;

		MakeTree( left, Range( curr.start, mid ) );
		MakeTree( right, Range( mid + 1, curr.end ) );

		tree[me] = min( tree[left], tree[right] );
	}
}

int GetMinValue( int me, Range curr, Range& segment ) {
	if ( curr.end < segment.start || segment.end < curr.start )
		return MAX;
	else if ( segment.start <= curr.start && curr.end <= segment.end )
		return tree[me];
	else {
		int mid = curr.getMid();
		int left = me * 2, right = me * 2 + 1;

		return min(
			GetMinValue( left, Range( curr.start, mid ), segment ),
			GetMinValue( right, Range( mid + 1, curr.end ), segment )
		);
	}
}

void UpdateTree( int me, Range curr, int& idx, int& value ) {
	if ( curr.start == curr.end && curr.start == idx )
		tree[me] = value;
	else if ( curr.end < idx || idx < curr.start )
		return;
	else {
		int mid = curr.getMid();
		int left = me * 2, right = me * 2 + 1;

		UpdateTree( left, Range( curr.start, mid ), idx, value );
		UpdateTree( right, Range( mid + 1, curr.end ), idx, value );

		tree[me] = min( tree[left], tree[right] );
	}
}
