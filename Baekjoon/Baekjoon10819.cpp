// Baekjoon10819_MaxDifference.cpp
// https://www.acmicpc.net/problem/10819
#include <iostream>
#include <vector>

#define ABS( a ) ( ( a ) > 0 ? ( a ) : -( a ) )

using namespace std;

int n, maxVal = 0;
int arr[8];
bool visited[8];

void backtracking( vector<int>& perm ) {
	if ( perm.size() == n ) {
		int temp = 0;
		for ( int i = 0; i < n - 1; i++ ) {
			temp += ABS( perm[i] - perm[i + 1] );
		}

		maxVal = max( maxVal, temp );
	} else {
		for ( int i = 0; i < n; i++ ) {
			if ( !visited[i] ) {
				visited[i] = true;
				perm.push_back( arr[i] );
				backtracking( perm );
				perm.pop_back( );
				visited[i] = false;
			}
		}
	}
}

int main(void) {
	cin >> n;

	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	vector<int> perm;
	backtracking( perm );

	cout << maxVal << '\n';

	return 0;
}
