// Baekjoon14650.cpp
// https://www.acmicpc.net/problem/14650
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	// dp[i][j] : i개의 자리수로 다 더해 j를 만들 수 있는 경우의 수
	int dp[10][19] = { 0, };
	dp[1][0] = dp[1][1] = dp[1][2] = 1;
	for (int i = 2; i < n; i++) {
		dp[i][0] = dp[i - 1][0];
		dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
		for (int j = 0; j <= 18; j++)
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j - 2];
	}

	int ans = 0;
	for (int i = 3; i <= 18; i += 3)
		ans += dp[n - 1][i - 1] + dp[n - 1][i - 2];

	cout << ans << '\n';

	return 0;
}