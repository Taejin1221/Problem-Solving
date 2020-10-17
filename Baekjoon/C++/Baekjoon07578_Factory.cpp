// Baekjoon07578_Factory.cpp
// https://www.acmicpc.net/problem/7578
#include <iostream>
#include <algorithm>

#define endl '\n'
#define MAX_ARR_SIZE 500'000
#define MAX_TREE_SIZE 2'000'000
#define MAX_TABLE_SIZE 1'000'001

using namespace std;

struct Range {
	int start, end;
	Range(): start(0), end(0) { }
	Range(int s, int e): start(s), end(e) { }
	int getMid() {
		return ( start + end ) / 2;
	}
};

int tree[MAX_TREE_SIZE];

int GetSum( int me, Range curr, Range& range );
void UpdateTreeTo1( int me, Range curr, int& idx );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int a[MAX_ARR_SIZE];
	int b_table[MAX_TABLE_SIZE];

	for ( int i = 0; i < n; i++ )
		cin >> a[i];

	for ( int i = 0; i < n; i++ ) {
		int temp;
		cin >> temp;

		b_table[temp] = i;
	}

	long long ans = 0;
	Range wholeRange = Range( 0, n - 1 );

	for ( int i = 0; i < n; i++ ) {
		int idx = b_table[a[i]];

		Range range = Range( idx + 1, n - 1 );
		ans += (long long)GetSum( 1, wholeRange, range );

		UpdateTreeTo1( 1, wholeRange, idx );
	}

	cout << ans << endl;

	return 0;
}

int GetSum( int me, Range curr, Range& range ) {
	if ( range.end < curr.start || curr.end < range.start )
		return 0;
	else if ( range.start <= curr.start && curr.end <= range.end )
		return tree[me];
	else {
		int mid = curr.getMid();
		int left = me * 2, right = me * 2 + 1;

		return (
			GetSum( left, Range( curr.start, mid ), range ) +
			GetSum( right, Range( mid + 1, curr.end ), range )
		);
	}
}

void UpdateTreeTo1( int me, Range curr, int& idx ) {
	if ( curr.start == curr.end && curr.start == idx )
		tree[me] = 1;
	else if ( idx < curr.start || curr.end < idx )
		return;
	else {
		int mid = curr.getMid();
		int left = me * 2, right = me * 2 + 1;

		UpdateTreeTo1( left, Range( curr.start, mid ), idx );
		UpdateTreeTo1( right, Range( mid + 1, curr.end ), idx );

		tree[me] = tree[left] + tree[right];
	}
}
