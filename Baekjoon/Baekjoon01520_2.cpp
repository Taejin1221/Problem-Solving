// Baekjoon01520.cpp
#include <iostream>

#include <algorithm>

using namespace std;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int n, m;
int map[500][500], dp[500][500];

int dfs(int row, int col) {
	int result = 0;
	for (int i = 0; i < 4; i++) {
		int newRow = row + moves[i][0], newCol = col + moves[i][1];

		if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m) && (map[newRow][newCol] > map[row][col])) {
			result += (dp[newRow][newCol] == -1) ? dfs(newRow, newCol) : dp[newRow][newCol];
		}
	}

	dp[row][col] = result;

	return dp[row][col];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		fill(dp[i], dp[i] + m, -1);
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}

	dp[0][0] = 1;
	dfs(n - 1, m - 1);

	cout << dp[n - 1][m - 1] << '\n';

	return 0;
}

