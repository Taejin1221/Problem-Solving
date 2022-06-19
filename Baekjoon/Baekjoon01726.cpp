// Baekjoon01726.cpp
// https://www.acmicpc.net/problem/1726
#include <iostream>

#include <queue>

using namespace std;

using pii = pair<int, int>;

struct Status {
	int row, col;
	int dir;
	int instNum;

	Status(): row(0), col(0), dir(0), instNum(0) { }
	Status(int r, int c, int d, int i): row(r), col(c), dir(d), instNum(i) { }

	bool operator==(const Status& s2) const {
		return (row == s2.row) && (col == s2.col) && (dir == s2.dir);
	}

	int getNextDir(char turn) {
		if (dir == 1) {
			if (turn == 'r')
				return 3;
			else
				return 4;
		} else if (dir == 2) {
			if (turn == 'r')
				return 4;
			else
				return 3;
		} else if (dir == 3) {
			if (turn == 'r')
				return 2;
			else
				return 1;
		} else {
			if (turn == 'r')
				return 1;
			else
				return 2;
		}
	}

	pii go(int k) {
		if (dir == 1) {
			return { row, col + k };
		} else if (dir == 2) {
			return { row, col - k };
		} else if (dir == 3) {
			return { row + k, col };
		} else {
			return { row - k, col };
		}
	}
};

int n, m;
bool orbit[100][100];

bool canGo(Status stat, int k) {
	int deltaRow = 0, deltaCol = 0;
	if (stat.dir == 1) {
		deltaCol = 1;
	} else if (stat.dir == 2) {
		deltaCol = -1;
	} else if (stat.dir == 3) {
		deltaRow = 1;
	} else {
		deltaRow = -1;
	}

	for (int i = 1; i <= k; i++) {
		int nextRow = stat.row + deltaRow * i, nextCol = stat.col + deltaCol * i;
		if ((0 <= nextRow && nextRow < n) && (0 <= nextCol && nextCol < m)) {
			if (!orbit[nextRow][nextCol])
				return false;
		} else
			return false;
	}

	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> orbit[i][j];
			orbit[i][j] = !orbit[i][j];
		}
	}

	Status start, end;
	cin >> start.row >> start.col >> start.dir;
	cin >> end.row >> end.col >> end.dir;

	start.row--, start.col--;
	end.row--, end.col--;

	queue<Status> q;
	bool visited[100][100][4] = { { { false, }, }, };

	q.push(start);
	visited[start.row][start.col][start.dir] = true;

	int ans = 0;
	while (!q.empty()) {
		Status curr = q.front(); q.pop();
		if (curr == end) {
			ans = curr.instNum;
			break;
		}

		int nextInstNum = curr.instNum + 1;
		if (!visited[curr.row][curr.col][curr.getNextDir('r')]) {
			visited[curr.row][curr.col][curr.getNextDir('r')] = true;
			q.push(Status(curr.row, curr.col, curr.getNextDir('r'), nextInstNum));
		}

		if (!visited[curr.row][curr.col][curr.getNextDir('l')]) {
			visited[curr.row][curr.col][curr.getNextDir('l')] = true;
			q.push(Status(curr.row, curr.col, curr.getNextDir('l'), nextInstNum));
		}

		for (int i = 1; i <= 3; i++) {
			pii nextPosition = curr.go(i);
			int nextRow = nextPosition.first, nextCol = nextPosition.second;

			int currDir = curr.dir;
			if (canGo(curr, i) && !visited[nextRow][nextCol][currDir]) {
				visited[nextRow][nextCol][currDir] = true;
				q.push(Status(nextRow, nextCol, currDir, nextInstNum));
			}
		}
	}

	cout << ans << '\n';

	return 0;
}