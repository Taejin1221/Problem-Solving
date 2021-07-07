// Baekjoon15654_NandM(5).cpp
// https://www.acmicpc.net/problem/15654
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int nums[8];
int sequence[8];
bool visited[8];

void backtracking( int size );

int main(void) {
	cin >> n >> m;

	for ( int i = 0; i < n; i++ )
		cin >> nums[i];
	sort( nums, nums + n );

	backtracking( 0 );

	return 0;
}

void backtracking( int size ) {
	if ( size == m ) {
		for ( int i = 0; i < m; i++ )
			cout << sequence[i] << ' ';
		cout << '\n';
	} else {
		for ( int i = 0; i < n; i++ ) {
			if ( !visited[i] ) {
				visited[i] = true;
				sequence[size] = nums[i];
				backtracking( size + 1 );
				visited[i] = false;
			}
		}
	}
}