// Baekjoon14494_WhatIsDynamic.cpp
// https://www.acmicpc.net/problem/14494
#include <iostream>

#define MOD 1'000'000'007

using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;

	long dp[1'000][1'000];
	for (int i = 0; i < m; i++)
		dp[0][i] = 1;

	for (int i = 0; i < n; i++)
		dp[i][0] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % MOD;
		}
	}

	cout << dp[n - 1][m - 1] << '\n';

	return 0;
}