// Baekjoon13565.cpp
// https://www.acmicpc.net/problem/13565
#include <iostream>

#include <queue>

using namespace std;

const int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };

int n, m;
char grid[1000][1000];
bool ans, visited[1000][1000];

void dfs(int row, int col) {
	if (row == n - 1)
		ans = true;
	else {
		for (int i = 0; i < 4; i++) {
			int ny = row + dy[i], nx = col + dx[i];
			if ((0 <= ny && ny < n) && (0 <= nx && nx < m)) {
				if (!visited[ny][nx] && grid[ny][nx] == '0') {
					visited[ny][nx] = true;
					dfs(ny, nx);
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> grid[i];

	for (int i = 0; i < m; i++) {
		if (!visited[0][i] && grid[0][i] == '0') {
			visited[0][i] = true;
			dfs(0, i);
		}
	}

	if (ans)
		cout << "YES";
	else
		cout << "NO";
	cout << '\n';

	return 0;
}