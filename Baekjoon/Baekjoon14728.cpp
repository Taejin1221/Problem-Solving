// Baekjoon14728_Cram.cpp
// https://www.acmicpc.net/problem/14728
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, t;
	cin >> n >> t;

	int info[100][2];
	for ( int i = 0; i < n; i++ )
		cin >> info[i][0] >> info[i][1];

	int dp[10001][100] = { 0, };
	for ( int currTime = 1; currTime <= t; currTime++ ) {
		dp[currTime][0] = ( currTime >= info[0][0] ) ? info[0][1] : 0;
		for ( int idx = 1; idx < n; idx++ ) {
			dp[currTime][idx] = dp[currTime][idx - 1];
			if ( currTime >= info[idx][0] )
				dp[currTime][idx] = max( dp[currTime - info[idx][0]][idx - 1] + info[idx][1], dp[currTime][idx] );
		}
	}

	cout << dp[t][n - 1] << '\n';

	return 0;
}