// Baekjoon02253_Jump.cpp
// https://www.acmicpc.net/problem/2253
#include <iostream>
#include <algorithm>

#define INF 10'001

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	bool small[INF] = { false, };
	for ( int i = 0; i < m; i++ ) {
		int temp;
		cin >> temp;

		small[temp] = true;
	}

	// row: stone, col: jump
	int dp[INF][250];
	for ( int i = 1; i <= n; i++ )
		fill( dp[i], dp[i] + 250, INF );

	dp[1][0] = 0;
	for ( int i = 1; i <= n; i++ ) { 
		if ( !small[i] ) {
			for ( int j = 0; j < 250; j++ ) {
				for ( int k = j - 1; k <= j + 1 && k < 250; k++ ) {
					if ( 0 < k && i + k <= n ) {
						if ( !small[i + k] )
							dp[i + k][k] = min( dp[i + k][k], dp[i][j] + 1 );
					}
				}
			}
		}
	}

	int ans = INF;
	for ( int i = 1; i < 250; i++ ) {
		ans = min( ans, dp[n][i] );
	}

	if ( ans == INF )
		cout << -1;
	else
		cout << ans;
	cout << '\n';

	return 0;
}
