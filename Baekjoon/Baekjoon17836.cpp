// Baekjoon17836.cpp
// https://www.acmicpc.net/problem/17836
#include <iostream>

#include <queue>

#define INF 1'000'000'000

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> node;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int n, m, t;
int castle[100][100];

int bfs(pii start, pii end, bool hasGram = false) {
	bool visited[100][100] = { false, };

	queue<node> q;

	q.push({ start, 0 });
	visited[start.first][start.second] = true;

	while (!q.empty()) {
		node curr = q.front(); q.pop();
		if (curr.first == end)
			return curr.second;

		pii currPos = curr.first;
		for (int i = 0; i < 4; i++) {
			int nextRow = currPos.first + moves[i][0], nextCol = currPos.second + moves[i][1];
			if ((0 <= nextRow && nextRow < n) && (0 <= nextCol && nextCol < m)) {
				if (!visited[nextRow][nextCol] && (hasGram || castle[nextRow][nextCol] != 1)) {
					visited[nextRow][nextCol] = true;
					q.push({ { nextRow, nextCol }, curr.second + 1 });
				}
			}
		}
	}

	return INF;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> t;

	pii gram;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> castle[i][j];
			if (castle[i][j] == 2)
				gram = { i, j };
		}
	}

	int path1 = bfs({ 0, 0 }, gram) + bfs(gram, { n - 1 , m - 1 }, true);
	int path2 = bfs({ 0, 0 }, { n - 1, m - 1 });

	if (min(path1, path2) <= t)
		cout << min(path1, path2);
	else
		cout << "Fail";
	cout << '\n';

	return 0;
}