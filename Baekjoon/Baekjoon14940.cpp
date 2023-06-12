// Baekjoon14940.cpp
// https://www.acmicpc.net/problem/14940
#include <iostream>

#include <queue>
#include <vector>

#define R first
#define C second

using namespace std;

using pii = pair<int, int>;

const pii moves[4] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	pii start;

	int map[1'000][1'000];
	vector<vector<int>> ans(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				start = { i, j };
			else if (map[i][j] == 0)
				ans[i][j] = 0;
		}
	}

	bool visited[1'000][1'000] = { { false, } };

	ans[start.R][start.C] = 0;
	visited[start.R][start.C] = true;

	queue<pii> q;
	q.push(start);

	while (!q.empty()) {
		pii curr = q.front(); q.pop();
		int currDistance = ans[curr.R][curr.C];

		for (int i = 0; i < 4; i++) {
			int newRow = curr.R + moves[i].R, newCol = curr.C + moves[i].C;
			if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m)) {
				if (map[newRow][newCol] == 1 && !visited[newRow][newCol]) {
					visited[newRow][newCol] = true;
					ans[newRow][newCol] = currDistance + 1;

					q.push({ newRow, newCol });
				} else if (map[newRow][newCol] == 0 && !visited[newRow][newCol]) {
					visited[newRow][newCol] = true;
					ans[newRow][newCol] = 0;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
}