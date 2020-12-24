// Baekjoon17070_MovePipe1.cpp
// https://www.acmicpc.net/problem/17070
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int house[16][16];
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			cin >> house[i][j];

	// 0: horizon, 1: vertical, 2: diagonal
	int dp[3][16][16] = { 0, };
	dp[0][0][1] = 1;

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 1; j < n; j++ ) {
			if ( dp[0][i][j] ) {
				if ( j + 1 < n && house[i][j + 1] == 0 )
					dp[0][i][j + 1] += dp[0][i][j];

				if ( (i + 1 < n && j + 1 < n) &&
					( house[i][j + 1] == 0 && house[i + 1][j] == 0 && house[i + 1][j + 1] == 0 ) )
					dp[2][i + 1][j + 1] += dp[0][i][j];
			}

			if ( dp[1][i][j] ) {
				if ( i + 1 < n && house[i + 1][j] == 0 )
					dp[1][i + 1][j] += dp[1][i][j];

				if ( (i + 1 < n && j + 1 < n) &&
					( house[i][j + 1] == 0 && house[i + 1][j] == 0 && house[i + 1][j + 1] == 0 ) )
					dp[2][i + 1][j + 1] += dp[1][i][j];
			}

			if ( dp[2][i][j] ) {
				if ( j + 1 < n && house[i][j + 1] == 0 )
					dp[0][i][j + 1] += dp[2][i][j];

				if ( i + 1 < n && house[i + 1][j] == 0 )
					dp[1][i + 1][j] += dp[2][i][j];

				if ( (i + 1 < n && j + 1 < n) &&
					( house[i][j + 1] == 0 && house[i + 1][j] == 0 && house[i + 1][j + 1] == 0 ) )
					dp[2][i + 1][j + 1] += dp[2][i][j];
			}
		}
	}

	cout << dp[0][n - 1][n - 1] + dp[1][n - 1][n - 1] + dp[2][n - 1][n - 1] << '\n';

	return 0;
}
