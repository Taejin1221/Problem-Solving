// Baekjoon15990_Plus123V.cpp
// https://www.acmicpc.net/problem/15990
#include <iostream>

#define MOD 1'000'000'009

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long dp[4][100'001] = { 0, };
	dp[0][1] = dp[1][1] = 1;
	dp[0][2] = dp[2][2] = 1;
	dp[1][3] = dp[2][3] = dp[3][3] = 1;
	dp[0][3] = 3;

	for ( int i = 4; i <= 100'000; i++ ) {
		dp[1][i] = ( dp[2][i - 1] + dp[3][i - 1] ) % MOD;
		dp[2][i] = ( dp[1][i - 2] + dp[3][i - 2] ) % MOD;
		dp[3][i] = ( dp[1][i - 3] + dp[2][i - 3] ) % MOD;
		dp[0][i] = ( dp[1][i] + dp[2][i] + dp[3][i] ) % MOD;
	}

	int t;
	cin >> t;
	while ( t-- ) {
		int n;
		cin >> n;

		cout << dp[0][n] << '\n';
	}

	return 0;
}