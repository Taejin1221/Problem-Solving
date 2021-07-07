// Baekjoon11048_Move.cpp
// https://www.acmicpc.net/problem/11048
#include <iostream>

#define MAX 1000

using namespace std;

int max3( int a, int b, int c ) {
	return max( a, max( b, c ) );
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int mat[MAX][MAX];
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < m; j++ )
			cin >> mat[i][j];

	int dp[MAX][MAX];
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < m; j++ ) {
			if ( i == 0 && j == 0 )
				dp[i][j] = 0;
			else if ( i == 0 )
				dp[i][j] = dp[i][j - 1];
			else if ( j == 0 )
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max3( dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] );
			dp[i][j] += mat[i][j];
		}
	}

	cout << dp[n - 1][m - 1] << '\n';

	return 0;
}
