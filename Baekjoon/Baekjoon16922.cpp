// Baekjoon16922.cpp
// https://www.acmicpc.net/problem/16922
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	bool dp[21][1'001] = { { false, }, };
	dp[1][1] = dp[1][5] = dp[1][10] = dp[1][50] = true;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 1'000; j++) {
			dp[i][j] |= dp[i - 1][j - 1];
			if (j > 5)
				dp[i][j] |= dp[i - 1][j - 5];
			if (j > 10)
				dp[i][j] |= dp[i - 1][j - 10];
			if (j > 50)
				dp[i][j] |= dp[i - 1][j - 50];
		}
	}

	int ans = 0;
	for (int i = 1; i <= 1'000; i++)
		ans += dp[n][i];

	cout << ans << '\n';

	return 0;
}