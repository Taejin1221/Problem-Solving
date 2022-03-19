// Baekjoon01584.cpp
// https://www.acmicpc.net/problem/1584
#include <iostream>

#include <queue>

using namespace std;

struct Node {
	int row, col;
	int cost;

	Node(): row(0), col(0), cost(0) {}
	Node(int r, int c, int w): row(r), col(c), cost(w) {}

	bool operator<(const Node& n2) const {
		return cost > n2.cost;
	}
};

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int areaInfo[501][501];

void setArea(int x1, int x2, int y1, int y2, int currArea) {
	int startX = min(x1, x2), endX = max(x1, x2);
	int startY = min(y1, y2), endY = max(y1, y2);

	for (int i = startY; i <= endY; i++)
		for (int j = startX; j <= endX; j++)
			areaInfo[i][j] = max(areaInfo[i][j], currArea);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		setArea(x1, x2, y1, y2, 1);
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		setArea(x1, x2, y1, y2, 2);
	}

	priority_queue<Node> pq;
	bool visited[501][501] = { { false, }, };

	pq.push(Node());

	int ans = -1;
	while (!pq.empty()) {
		Node curr = pq.top(); pq.pop();
		if (curr.row == 500 && curr.col == 500) {
			ans = curr.cost;
			break;
		}

		int currRow = curr.row, currCol = curr.col;
		if (!visited[currRow][currCol]) {
			visited[currRow][currCol] = true;
			for (int i = 0; i < 4; i++) {
				int nextRow = currRow + moves[i][0], nextCol = currCol + moves[i][1];
				if ((0 <= nextRow && nextRow <= 500) && (0 <= nextCol && nextCol <= 500))
					if (!visited[nextRow][nextCol] && areaInfo[nextRow][nextCol] != 2)
						pq.push(Node(nextRow, nextCol, curr.cost + areaInfo[nextRow][nextCol]));
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
