// Baekjoon21736.cpp
// https://www.acmicpc.net/problem/21736
#include <iostream>

#include <queue>

#define ROW first
#define COL second

using namespace std;

using pii = pair<int, int>;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	pii start = { 0, 0 };
	char campus[600][601];
	for (int i = 0; i < n; i++) {
		cin >> campus[i];
		for (int j = 0; j < m; j++)
			if (campus[i][j] == 'I')
				start = { i, j };
	}

	queue<pii> q;
	bool visited[600][601] = { { false, } };

	q.push(start);
	visited[start.ROW][start.COL] = true;

	int ans = 0;
	while (!q.empty()) {
		pii curr = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nextRow = curr.ROW + moves[i][0], nextCol = curr.COL + moves[i][1];
			if ((0 <= nextRow && nextRow < n) && (0 <= nextCol && nextCol < m)) {
				if (!visited[nextRow][nextCol] && campus[nextRow][nextCol] != 'X') {
					visited[nextRow][nextCol] = true;
					ans += campus[nextRow][nextCol] == 'P';
					q.push({ nextRow, nextCol });
				}
			}
		}
	}

	if (ans == 0)
		cout << "TT";
	else
		cout << ans;
	cout << '\n';

	return 0;
}