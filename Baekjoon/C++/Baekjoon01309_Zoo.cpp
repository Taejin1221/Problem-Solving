// Baekjoon01309_Zoo.cpp
// https://www.acmicpc.net/problem/1309
#include <iostream>

#define MOD 9901

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int dp[4][100'001];
	dp[0][1] = dp[1][1] = dp[2][1] = 1;
	dp[3][1] = 3;

	for ( int i = 2; i <= n; i++ ) {
		dp[0][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % MOD;
		dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % MOD;
		dp[2][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
		dp[3][i] = (dp[0][i] + dp[1][i] + dp[2][i]) % MOD;
	}

	cout << dp[3][n] << '\n';

	return 0;
}