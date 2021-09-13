// Baekjoon22114.cpp
// https://www.acmicpc.net/problem/22114
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int blocks[100'000];
	for (int i = 0; i < n - 1; i++)
		cin >> blocks[i];

	int dp[2][100'000] = { 0, };

	int ans = 1;
	dp[0][n - 1] = dp[1][n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (blocks[i] <= k) {
			dp[0][i] = dp[0][i + 1] + 1;
			dp[1][i] = dp[1][i + 1] + 1;
		} else {
			dp[0][i] = 1;
			dp[1][i] = dp[0][i + 1] + 1;
		}

		ans = max(ans, max(dp[0][i], dp[1][i]));
	}

	cout << ans << '\n';

	return 0;
}