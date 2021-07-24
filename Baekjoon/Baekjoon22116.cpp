// Baekjoon22116.cpp
// https://www.acmicpc.net/problem/22116
#include <iostream>

#include <queue>

#define abs(x) ((x) > 0 ? x : -(x))

using namespace std;

struct Node {
	int row, col;
	int slope;
	Node(int r, int c, int s): row(r), col(c), slope(s) { }
	bool operator<(const Node& n2) const {
		return slope > n2.slope;
	}
};

const int changes[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int grid[1'000][1'000];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> grid[i][j];

	priority_queue<Node> pq;
	bool visited[1'000][1'000] = { { false, }, };

	pq.push(Node(0, 0, 0));

	int ans = 0;
	while (!pq.empty()) {
		Node currNode = pq.top(); pq.pop();

		if (currNode.row == n - 1 && currNode.col == n - 1) {
			ans = max(ans, currNode.slope);
			break;
		}

		if (!visited[currNode.row][currNode.col]) {
			visited[currNode.row][currNode.col] = true;
			ans = max(ans, currNode.slope);

			for (int i = 0; i < 4; i++) {
				int newRow = currNode.row + changes[i][0], newCol = currNode.col + changes[i][1];
				if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < n))
					if (!visited[newRow][newCol])
						pq.push(Node(newRow, newCol, abs(grid[currNode.row][currNode.col] - grid[newRow][newCol])));
			}
		}
	}

	cout << ans << '\n';

	return 0;
}