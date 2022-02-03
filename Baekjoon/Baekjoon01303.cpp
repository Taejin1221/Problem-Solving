// Baekjoon01303.cpp
// https://www.acmicpc.net/problem/1303
#include <iostream>

using namespace std;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int n, m;
char colorMap[100][101];
bool visited[100][100];

int dfs(int row, int col) {
	int result = 0;
	for (int i = 0; i < 4; i++) {
		int newRow = row + moves[i][0], newCol = col + moves[i][1];
		if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m)) {
			if (!visited[newRow][newCol] && colorMap[newRow][newCol] == colorMap[row][col]) {
				visited[newRow][newCol] = true;
				result += dfs(newRow, newCol);
			}
		}
	}

	return result + 1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++)
		cin >> colorMap[i];

	pair<int, int> ans = { 0, 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;

				int currAns = dfs(i, j);
				(colorMap[i][j] == 'W' ? ans.first : ans.second) += (currAns * currAns);
			}
		}
	}

	cout << ans.first << ' ' << ans.second << '\n';

	return 0;
}