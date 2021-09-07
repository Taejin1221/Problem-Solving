// Baekjoon01743.cpp
// https://www.acmicpc.net/problem/1743
#include <iostream>

#include <algorithm>

using namespace std;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int n, m, k;
char map[100][100];
bool visited[100][100];

int dfs(int row, int col) {
	int ans = 1;
	for (int i = 0; i < 4; i++) {
		int newRow = row + moves[i][0], newCol = col + moves[i][1];
		if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m)) {
			if (!visited[newRow][newCol] && map[newRow][newCol] == '#') {
				visited[newRow][newCol] = true;
				ans += dfs(newRow, newCol);
			}
		}
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		fill(map[i], map[i] + m, '.');

	for (int i = 0; i < k; i++) {
		int row, col;
		cin >> row >> col;

		map[row - 1][col - 1] = '#';
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && map[i][j] == '#') {
				visited[i][j] = true;
				ans = max(ans, dfs(i, j));
			}
		}
	}

	cout << ans << '\n';

	return 0;
}