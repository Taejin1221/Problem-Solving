// Baekjoon02357_MinMax.cpp
// https://www.acmicpc.net/problem/2357
#include <iostream>

#define endl '\n'
#define MAX 1
#define MIN 1'000'000'000
#define MAX_ARR_SIZE 100'000
#define MAX_TREE_SIZE 400'000

using namespace std;

struct Range {
	int s, e;
	Range() {}
	Range( int start, int end ): s(start), e(end) {}
	int getMid() { return ( s + e ) / 2; }
};

Range segment;
int arr[MAX_ARR_SIZE];
int maxTree[MAX_TREE_SIZE];
int minTree[MAX_TREE_SIZE];

void MakeMinTree( int me, Range range );
void MakeMaxTree( int me, Range range );
int GetMin( int me, Range range );
int GetMax( int me, Range range );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	Range wholeRange = Range( 0, n - 1 );
	MakeMinTree( 1, wholeRange ); MakeMaxTree( 1, wholeRange );
	for ( int i = 0; i < m; ++i ) {
		int start, end;
		cin >> start >> end;

		segment.s = start - 1; segment.e = end - 1;
		cout << GetMin( 1, wholeRange ) << ' ' << GetMax( 1, wholeRange ) << endl;
	}

	return 0;
}

void MakeMinTree( int me, Range range ) {
	if ( range.s == range.e )
		minTree[me] = arr[range.s];
	else {
		int mid = range.getMid();
		int left = me * 2, right = me * 2 + 1;

		MakeMinTree( left, Range( range.s, mid ) );
		MakeMinTree( right, Range( mid + 1, range.e ) );

		minTree[me] = min( minTree[left], minTree[right] );
	}
}

void MakeMaxTree( int me, Range range ) {
	if ( range.s == range.e )
		maxTree[me] = arr[range.s];
	else {
		int mid = range.getMid();
		int left = me * 2, right = me * 2 + 1;

		MakeMaxTree( left, Range( range.s, mid ) );
		MakeMaxTree( right, Range( mid + 1, range.e ) );

		maxTree[me] = max( maxTree[left], maxTree[right] );
	}
}

int GetMin( int me, Range range ) {
	if ( segment.s <= range.s && range.e <= segment.e )
		return minTree[me];
	else if ( range.e < segment.s || segment.e < range.s )
		return MIN;
	else {
		int mid = range.getMid();
		int left = me * 2, right = me * 2 + 1;

		return ( min( GetMin( left, Range( range.s, mid ) ), GetMin( right, Range( mid + 1, range.e ) ) ) );
	}
}

int GetMax( int me, Range range ) {
	if ( segment.s <= range.s && range.e <= segment.e )
		return maxTree[me];
	else if ( range.e < segment.s || segment.e < range.s )
		return MAX;
	else {
		int mid = range.getMid();
		int left = me * 2, right = me * 2 + 1;

		return ( max( GetMax( left, Range( range.s, mid ) ), GetMax( right, Range( mid + 1, range.e ) ) ) );
	}
}