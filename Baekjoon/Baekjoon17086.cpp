// Baekjoon17086.cpp
// https://www.acmicpc.net/problem/17086
#include <iostream>

#include <queue>

using namespace std;

struct Node {
	int row, col, dist;
	Node(): row(0), col(0), dist(0) {}
	Node(int r, int c, int d): row(r), col(c), dist(d) { }
};

const int moves[8][2] = {
	{ -1, -1 },
	{ -1, 0 },
	{ -1, 1 },
	{ 0, -1 },
	{ 0, 1 },
	{ 1, -1 },
	{ 1, 0 },
	{ 1, 1 }
};

int n, m;
bool sea[50][50];

int bfs(int row, int col) {
	bool visited[50][50] = { { false, } };

	queue<Node> q;
	q.push(Node(row, col, 0));
	visited[row][col] = true;

	int res = 0;
	while (!q.empty()) {
		Node curr = q.front(); q.pop();
		if (sea[curr.row][curr.col]) {
			res = curr.dist;
			break;
		}

		for (int i = 0; i < 8; i++) {
			int newRow = curr.row + moves[i][0], newCol = curr.col + moves[i][1];
			if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m)) {
				if (!visited[newRow][newCol]) {
					visited[newRow][newCol] = true;
					q.push(Node(newRow, newCol, curr.dist + 1));
				}
			}
		}
	}

	return res;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> sea[i][j];

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ans = max(ans, bfs(i, j));

	cout << ans << '\n';

	return 0;
}