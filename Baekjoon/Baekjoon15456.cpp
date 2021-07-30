// Baekjoon15456.cpp
// https://www.acmicpc.net/problem/16456
#include <iostream>

#define MOD 1'000'000'009

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int dp[2][50'001];
	dp[0][1] = 1, dp[1][1] = 0;
	dp[0][2] = dp[1][2] = 1;

	for (int i = 3; i <= n; i++) {
		dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
		dp[1][i] = dp[0][i - 2];
	}

	cout << dp[0][n] << '\n';

	return 0;
}