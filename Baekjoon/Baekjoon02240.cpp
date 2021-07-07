// Baekjoon02240_PlumTree.cpp
// https://www.acmicpc.net/problem/2240
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, w;
	cin >> t >> w;

	int dp[1'002][2][31] = { 0, };

	int pos;
	cin >> pos;

	if ( pos == 1 ) {
		dp[2][0][0] = 1;
		dp[2][1][1] = 1;
	} else {
		dp[2][1][1] = 1;
		dp[2][0][2] = 1;
	}

	for ( int i = 2; i <= t; i++ ) {
		cin >> pos; pos--;
		for ( int j = 0; j <= 1; j++ ) {
			for ( int k = 0; k <= 30; k++ ) {
				dp[i][j][k] += (pos == j);

				dp[i + 1][j][k] = max( dp[i + 1][j][k], dp[i][j][k] );
				if ( k < 30 )
					dp[i + 1][!j][k + 1] = max( dp[i + 1][!j][k + 1], dp[i][j][k] );
			}
		}
	}

	int ans = 0;
	for ( int i = 0; i <= w; i++ )
		ans = max( ans, max( dp[t + 1][0][i], dp[t + 1][1][i] ) );

	cout << ans << '\n';

	return 0;
}