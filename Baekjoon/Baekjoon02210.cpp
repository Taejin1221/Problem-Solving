// Baekjoon02210.cpp
// https://www.acmicpc.net/problem/2210
#include <iostream>

#include <set>

using namespace std;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

set<int> numbers;
int board[5][5];

void dfs(int curr, int row, int col, int num) {
	if (num == 6) {
		numbers.insert(curr);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int newRow = row + moves[i][0], newCol = col + moves[i][1];
		if ((0 <= newRow && newRow < 5) && (0 <= newCol && newCol < 5))
			dfs(curr * 10 + board[newRow][newCol], newRow, newCol, num + 1);
	}
}

int main(void) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> board[i][j];

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(board[i][j], i, j, 1);
		}
	}

	cout << numbers.size() << '\n';

	return 0;
}