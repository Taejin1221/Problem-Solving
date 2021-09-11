// Baekjoon01562.cpp
// https://www.acmicpc.net/problem/1562
#include <iostream>

#define MOD 1'000'000'000

using namespace std;

typedef long long ll;

int main(void) {
	int n;
	cin >> n;

	ll dp[101][10][1024] = { 0, };
	for (int i = 1; i <= 9; i++)
		dp[1][i][1 << i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int k = 0; k < 1024; k++) {
			dp[i][0][k | 1 << 0] += dp[i - 1][1][k];
			dp[i][9][k | 1 << 9] += dp[i - 1][8][k];
		}

		for (int j = 1; j < 9; j++)
			for (int k = 0; k < 1024; k++)
				dp[i][j][k | 1 << j] += (dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k]) % MOD;
	}

	ll ans = 0ll;
	for (int i = 0; i < 10; i++)
		ans = (ans + dp[n][i][1023]) % MOD;
	cout << ans << '\n';

	return 0;
}