// Baekjoon15657_NandM(8).cpp
// https://www.acmicpc.net/problem/15657
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int nums[8];
int sequence[8];

void backtracking( int currIdx, int size );

int main(void) {
	cin >> n >> m;
	for ( int i = 0; i < n; i++ )
		cin >> nums[i];
	sort( nums, nums + n );

	backtracking( 0, 0 );

	return 0;
}

void backtracking( int currIdx, int size ) {
	if ( size == m ) {
		for ( int i = 0; i < m; i++ )
			cout << sequence[i] << ' ';
		cout << '\n';
	} else {
		for ( int i = currIdx; i < n; i++ ) {
			sequence[size] = nums[i];
			backtracking( i, size + 1);
		}
	}
}