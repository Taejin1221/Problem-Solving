// Baekjoon03055_Escape.cpp
// https://www.acmicpc.net/problem/3055
#include <iostream>

#include <queue>

using namespace std;

struct Node {
	int row, col;
	int time;

	Node(int r, int c): row(r), col(c), time(0) { }
	Node(int r, int c, int t): row(r), col(c), time(t) { }
};

const int moves[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int rowMax, colMax;
	cin >> rowMax >> colMax;

	queue<Node> hedgehogs;
	queue<Node> water;
	bool visited[50][50] = { false, };

	char grid[50][51];
	for (int i = 0; i < rowMax; i++) {
		cin >> grid[i];
		for (int j = 0; j < colMax; j++) {
			if (grid[i][j] == 'S') {
				hedgehogs.push(Node(i, j, 0));
				visited[i][j] = true;
				grid[i][j] = '.';
			} else if (grid[i][j] == '*') {
				water.push(Node(i, j));
			}
		}
	}

	int ans = -1, time = 0;
	while (!hedgehogs.empty() && ans == -1) {
		int waterNum = water.size();
		for (int i = 0; i < waterNum; i++) {
			Node w = water.front(); water.pop();
			for (int i = 0; i < 4; i++) {
				int newRow = w.row + moves[i][0], newCol = w.col + moves[i][1];
				if ((0 <= newRow && newRow < rowMax) && (0 <= newCol && newCol < colMax)) {
					if (grid[newRow][newCol] != 'X' && grid[newRow][newCol] != 'D' && grid[newRow][newCol] != '*') {
						grid[newRow][newCol] = '*';
						water.push(Node(newRow, newCol));
					}
				}
			}
		}

		while (!hedgehogs.empty() && hedgehogs.front().time == time) {
			Node h = hedgehogs.front(); hedgehogs.pop();
			if (grid[h.row][h.col] == 'D') {
				ans = h.time;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int newRow = h.row + moves[i][0], newCol = h.col + moves[i][1];
				if ((0 <= newRow && newRow < rowMax) && (0 <= newCol && newCol < colMax)) {
					if (grid[newRow][newCol] != 'X' && grid[newRow][newCol] != '*' && !visited[newRow][newCol]) {
						visited[newRow][newCol] = true;
						hedgehogs.push(Node(newRow, newCol, h.time + 1));
					}
				}
			}
		}

		time++;
	}

	if (ans == -1)
		cout << "KAKTUS";
	else
		cout << ans;
	cout << '\n';

	return 0;
}