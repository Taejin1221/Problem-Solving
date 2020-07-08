// Baekjoon02042_GetSegmentSum.cpp
// https://www.acmicpc.net/problem/2042
#include <iostream>

#define endl '\n'
#define MAX_ARR_SIZE 1'000'000
#define MAX_TREE_SIZE 4'000'001

using namespace std;

typedef long long ll;
struct Range {
	int start, end;
	Range() {}
	Range( int s, int e ): start( s ), end( e ) {}
};

ll arr[MAX_ARR_SIZE];
ll tree[MAX_TREE_SIZE];

void MakeTree( int me, Range range );
void UpdateTree( int me, int idx, ll diff, Range range );
ll GetSegmentSum( int me, Range range, Range segment );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for ( int i = 0; i < n; i++ )
		cin >> arr[i];
	Range total = Range( 0, n - 1 );

	MakeTree( 1, total );
	for ( int i = 0; i < ( m + k ); i++ ) {
		int opr;
		cin >> opr;

		if ( opr == 1 ) {
			int idx; ll val;
			cin >> idx >> val;

			ll diff = val - arr[--idx];
			arr[idx] = val;
			UpdateTree( 1, idx, diff, total );
		}
		else {
			int start, end;
			cin >> start >> end;
			cout << GetSegmentSum( 1, total, Range( start - 1, end - 1 ) ) << endl;
		}
	}

	return 0;
}

void MakeTree( int me, Range range ) {
	if ( range.start == range.end )
		tree[me] = arr[range.start];
	else {
		int mid = ( range.start + range.end ) / 2;
		int left = me * 2, right = me * 2 + 1;
		MakeTree( left, Range( range.start, mid ) );
		MakeTree( right, Range( mid + 1, range.end ) );

		tree[me] = tree[left] + tree[right];
	}
}

void UpdateTree( int me, int idx, ll diff, Range range ) {
	if  ( idx < range.start || range.end < idx )
		return;
	
	if ( range.start <= idx && idx <= range.end )
		tree[me] += diff;

	if ( range.start != range.end ) {
		int left = me * 2, right = me * 2 + 1;
		int mid = ( range.start + range.end ) / 2;

		UpdateTree( left, idx, diff, Range( range.start, mid ) );
		UpdateTree( right, idx, diff, Range( mid + 1, range.end ) );
	}
}

ll GetSegmentSum( int me, Range range, Range segment ) {
	if ( range.end < segment.start || segment.end < range.start )
		return 0;
	else if ( segment.start <= range.start && range.end <= segment.end)
		return tree[me];
	else {
		int left = me * 2, right = me * 2 + 1;
		int mid = ( range.start + range.end ) / 2;
		ll leftSum = GetSegmentSum( left, Range( range.start, mid ), segment );
		ll rightSum = GetSegmentSum( right, Range( mid + 1, range.end ), segment );

		return ( leftSum + rightSum );
	}
}
