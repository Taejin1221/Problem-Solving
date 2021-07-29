// Baekjoon01103.cpp
// https://www.acmicpc.net/problem/1103
#include <iostream>

#include <algorithm>

using namespace std;

int n, m;
char board[50][51];
int dp[50][51];
bool visited[50][51];

int func(int row, int col) {
	if (row < 0 || n <= row || col < 0 || m <= col)
		return 0;

	if (dp[row][col] == -1) {
		if (visited[row][col])
			return -1;
		visited[row][col] = true;

		if (board[row][col] == 'H')
			dp[row][col] = 0;
		else {
			int num = board[row][col] - '0';

			int values[4];
			values[0] = func(row - num, col);
			values[1] = func(row, col + num);
			values[2] = func(row + num, col);
			values[3] = func(row, col - num);

			bool isInfinite = false;
			for (int i = 0; i < 4; i++)
				if (values[i] == -1)
					isInfinite = true;

			if (isInfinite)
				return -1;

			dp[row][col] = max(max(values[0], values[1]), max(values[2], values[3])) + 1;
		}
	}

	return dp[row][col];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
		fill(dp[i], dp[i] + m, -1);
	}

	cout << func(0, 0) << '\n';

	return 0;
}