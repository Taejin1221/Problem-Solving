// Baekjoon14503.cpp
// https://www.acmicpc.net/problem/14503
#include <iostream>

using namespace std;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

struct Position {
	int row, col;
	Position(): row(0), col(0) { }
};

int leftDirection(int direction) {
	return direction == 0 ? 3 : direction - 1;
}

Position nextPosition(Position& currPosition, int direction) {
	Position result;
	result.row = currPosition.row + moves[direction][0];
	result.col = currPosition.col + moves[direction][1];

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int direction;
	Position start;

	cin >> start.row >> start.col >> direction;

	bool map[50][50];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	Position curr = start;
	bool visited[50][50] = { { false, } };
	visited[curr.row][curr.col] = true;

	int ans = 1;
	bool canGo = true;
	while (canGo) {
		canGo = false;
		for (int i = 0; i < 4; i++) {
			direction = leftDirection(direction);
			Position next = nextPosition(curr, direction);
			if (!visited[next.row][next.col] && !map[next.row][next.col]) {
				visited[next.row][next.col] = true;
				canGo = true;
				curr = next;
				ans++;

				break;
			}
		}

		if (!canGo) {
			Position next = nextPosition(curr, (direction + 2) % 4);
			if (!map[next.row][next.col]) {
				canGo = true;
				curr = next;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}