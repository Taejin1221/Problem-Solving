// Baekjoon01189.cpp
// https://www.acmicpc.net/problem/1189
#include <iostream>

using namespace std;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int r, c, k, ans;
char map[5][6];
bool visited[5][5];

void dfs(int row, int col, int distance = 1) {
	if (row == 0 && col == c - 1) {
		if (distance == k)
			ans++;
	} else {
		for (int i = 0; i < 4; i++) {
			int newRow = row + moves[i][0], newCol = col + moves[i][1];
			if ((0 <= newRow && newRow < r) && (0 <= newCol && newCol < c)) {
				if (!visited[newRow][newCol] && map[newRow][newCol] != 'T') {
					visited[newRow][newCol] = true;
					dfs(newRow, newCol, distance + 1);
					visited[newRow][newCol] = false;
				}
			}
		}
	}
}

int main(void) {
	cin >> r >> c >> k;

	for (int i = 0; i < r; i++)
		cin >> map[i];

	visited[r - 1][0] = true;
	dfs(r - 1, 0);

	cout << ans << '\n';

	return 0;
}