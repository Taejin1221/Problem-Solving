// Baekjoon10868_MinValue.cpp
// https://www.acmicpc.net/problem/10868
#include <iostream>

#define endl '\n'
#define INF 1'000'000'000
#define MAX_ARR_SIZE 100'000
#define MAX_TREE_SIZE 400'000

using namespace std;

struct Range {
	int s, e;
	Range() {}
	Range( int start, int end ): s(start), e(end) {}
	int getMid( ) {
		return ( s + e ) / 2;
	}
};

Range segment;
int arr[MAX_ARR_SIZE];
int tree[MAX_TREE_SIZE];

void MakeTree( int me, Range range );
int MinValue( int me, Range range );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	Range totalRange = Range( 0, n - 1 );
	MakeTree( 1, totalRange );
	for ( int i = 0; i < m; i++ ) {
		int start, end;
		cin >> start >> end;

		segment.s = start - 1;
		segment.e = end - 1;

		cout << MinValue( 1, totalRange ) << endl;
	}

	return 0;
}

void MakeTree( int me, Range range ) {
	if ( range.s == range.e )
		tree[me] = arr[range.s];
	else {
		int mid = range.getMid();
		int left = me * 2;
		int right = left + 1;

		MakeTree( left, Range( range.s, mid ) );
		MakeTree( right, Range( mid + 1, range.e ) );

		tree[me] = min( tree[left], tree[right] );
	}
}

int MinValue( int me, Range range ) {
	if ( segment.s <= range.s && range.e <= segment.e )
		return tree[me];
	else if ( segment.e < range.s || range.e < segment.s )
		return INF;
	else {
		int mid = range.getMid();
		int left = me * 2;
		int right = left + 1;

		return min( MinValue( left, Range( range.s, mid ) ), MinValue( right, Range( mid + 1, range.e ) ) );
	}
}