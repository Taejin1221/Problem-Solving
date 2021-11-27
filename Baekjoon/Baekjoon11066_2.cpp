// Baekjoon11066_2.cpp
// https://www.acmicpc.net/problem/11066
#include <iostream>

using namespace std;

using ll = long long;

void solveTestCase() {
	int n;
	cin >> n;

	// { fileSize, costSum }
	pair<ll, ll> dp[500][500] = { { { 0, 0 }, } };
	for (int i = 0; i < n; i++)
		cin >> dp[i][i].first;

	for (int i = 0; i < n - 1; i++) {
		dp[i][i + 1].first = dp[i][i].first + dp[i + 1][i + 1].first;
		dp[i][i + 1].second = dp[i][i].first + dp[i + 1][i + 1].first;
	}

	for (int dis = 2; dis < n; dis++) {
		for (int row = 0; row < n - dis; row++) {
			int col = row + dis;
			dp[row][col].second = 0x3f3f3f3f3f3f3f3f;
			for (int i = 0; i < dis; i++) {
				ll currFileSize = dp[row][row + i].first + dp[row + 1 + i][col].first;
				ll currCostSum = dp[row][row + i].second + dp[row + 1 + i][col].second + currFileSize;
				if (dp[row][col].second > currCostSum) {
					dp[row][col].first = currFileSize;
					dp[row][col].second = currCostSum;
				}
			}
		}
	}

	cout << dp[0][n - 1].second << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solveTestCase();
	}

	return 0;
}