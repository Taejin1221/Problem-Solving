// Baekjoon12849_CampusTour.cpp
// https://www.acmicpc.net/problem/12849
#include <iostream>

#define MOD 1'000'000'007

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	// row: minute, col: position
	long dp[100'001][8] = { 0, };
	dp[0][0] = 1;

	for ( int i = 1; i <= n; i++ ) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][4]) % MOD;
		dp[i][3] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][5]) % MOD;
		dp[i][4] = (dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][6]) % MOD;
		dp[i][5] = (dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][7]) % MOD;
		dp[i][6] = (dp[i - 1][4] + dp[i - 1][7]) % MOD;
		dp[i][7] = (dp[i - 1][5] + dp[i - 1][6]) % MOD;
	}

	cout << dp[n][0] << '\n';

	return 0;
}