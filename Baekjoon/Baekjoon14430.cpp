// Baekjoon14430.cpp
// https://www.acmicpc.net/problem/14430
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int mineral[300][300];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mineral[i][j];

	int dp[300][300] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = mineral[i][j];
			if (i == 0 && j == 0)
				continue;
			else if (i == 0)
				dp[i][j] += dp[i][j - 1];
			else if (j == 0)
				dp[i][j] += dp[i - 1][j];
			else
				dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[n - 1][m - 1] << endl;

	return 0;
}