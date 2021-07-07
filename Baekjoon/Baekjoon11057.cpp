// Baekjoon11057_AscentNumber.cpp
// https://www.acmicpc.net/problem/11057
#include <iostream>

#define MOD 10'007

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int dp[1001][11] = { 0, };
	for ( int i = 9; i >= 0; i-- )
		dp[1][i] = dp[1][i + 1] + 1;

	for ( int i = 2; i <= n; i++ ) {
		for ( int j = 0; j < 10; j++ )
			dp[i][j] = (dp[i - 1][j]) % MOD;

		for ( int j = 9; j >= 0; j-- )
			dp[i][j] = (dp[i][j + 1] + dp[i][j]) % MOD;
	}

	cout << dp[n][0] << '\n';

	return 0;
}