// Baekjoon10835_CardGame.cpp
// https://www.acmicpc.net/problem/10835
#include <iostream>

#include <algorithm>

#define SIZE 2'001

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int A[SIZE], B[SIZE];
	for ( int i = 0; i < n; i++ )
		cin >> A[i];

	for ( int i = 0; i < n; i++ )
		cin >> B[i];

	// dp[i][j] => A index, B index
	int dp[SIZE][SIZE];
	for ( int i = 0; i <= n; i++ )
		fill( dp[i], dp[i] + n + 1, -1 );

	dp[0][0] = 0;
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			if ( dp[i][j] != -1 ){
				dp[i + 1][j + 1] = max( dp[i + 1][j + 1], dp[i][j] );
				dp[i + 1][j] = max( dp[i + 1][j], dp[i][j] );
				if ( A[i] > B[j] )
					dp[i][j + 1] = max( dp[i][j + 1], dp[i][j] + B[j] );}
		}
	}

	int ans = dp[n][n];
	for ( int i = 0; i < n; i++ ) {
		ans = max( ans, dp[i][n] );
		ans = max( ans, dp[n][i] );
	}

	cout << ans << '\n';

	return 0;
}