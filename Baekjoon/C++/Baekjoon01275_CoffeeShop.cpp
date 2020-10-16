// Baekjoon01275_CoffeeShop.cpp
// https://www.acmicpc.net/problem/1275
#include <iostream>

#define endl '\n'
#define MAX_ARR_SIZE 100'000
#define MAX_TREE_SIZE 400'000

using namespace std;

typedef long long ll;

struct Range {
	int start, end;
	Range( ): start(0), end(0) { }
	Range( int s, int e ): start(s), end(e) { }
	int getMid();
	void decrement();
};

int arr[MAX_ARR_SIZE];
ll tree[MAX_TREE_SIZE];

void MakeTree( int me, Range curr );
ll GetSum( int me, Range curr, Range& segment );
void ModifyValue( int me, Range curr, int& idx, int& value );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, q;
	cin >> n >> q;

	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	Range wholeRange = Range( 0, n - 1 );
	MakeTree( 1, wholeRange );
	while ( q-- ) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;

		Range segment;
		if ( x <= y ) {
			segment.start = x;
			segment.end = y;
		} else {
			segment.start = y;
			segment.end = x;
		}
		segment.decrement();

		ll sum = GetSum( 1, wholeRange, segment );
		cout << sum << '\n';

		a--;
		ModifyValue( 1, wholeRange, a, b );
	}
}

int Range::getMid() {
	return ( start + end ) / 2;
}

void Range::decrement() {
	start--;
	end--;
}

void MakeTree( int me, Range curr ) {
	if ( curr.start == curr.end )
		tree[me] = arr[curr.start];
	else {
		int mid = curr.getMid();
		int left = me * 2, right = me * 2 + 1;

		MakeTree( left, Range( curr.start, mid ) );
		MakeTree( right, Range( mid + 1, curr.end ) );

		tree[me] = tree[left] + tree[right];
	}
}

ll GetSum( int me, Range curr, Range& segment ) {
	if ( segment.end < curr.start || curr.end < segment.start )
		return 0;
	else if ( segment.start <= curr.start && curr.end <= segment.end )
		return (ll)tree[me];
	else {
		int mid = curr.getMid();
		int left = me * 2, right = me * 2 + 1;

		return (
			GetSum( left, Range( curr.start, mid ), segment ) + 
			GetSum( right, Range( mid + 1, curr.end ), segment )
		);
	}
}

void ModifyValue( int me, Range curr, int& idx, int& value ) {
	if ( curr.start == curr.end && curr.start == idx )
		tree[me] = value;
	else if ( idx < curr.start || curr.end < idx )
		return;
	else {
		int mid = curr.getMid();
		int left = me * 2, right = me * 2 + 1;

		ModifyValue( left, Range( curr.start, mid ), idx, value );
		ModifyValue( right, Range( mid + 1, curr.end ), idx, value );

		tree[me] = tree[left] + tree[right];
	}
}
