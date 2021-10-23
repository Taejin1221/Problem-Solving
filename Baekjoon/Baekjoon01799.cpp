// Baekjoon01799.cpp
// https://www.acmicpc.net/problem/1799
#include <iostream>

using namespace std;

int n, ans[2];
bool canPut[10][10], isNotValid[20];

void backtracking(int diagonal, int bishopSize, int num) {
	if (diagonal >= n * 2 - 1)
		ans[num] = max(ans[num], bishopSize);
	else {
		int row = diagonal < n ? n - 1 - diagonal : 0;
		int col = diagonal < n ? 0 : diagonal - (n - 1);
		for (int newRow = row, newCol = col; newRow < n && newCol < n; newRow++, newCol++) {
			if (canPut[newRow][newCol] && !isNotValid[newRow + newCol]) {
				isNotValid[newRow + newCol] = true;
				backtracking(diagonal + 2, bishopSize + 1, num);
				isNotValid[newRow + newCol] = false;
			}
		}
		backtracking(diagonal + 2, bishopSize, num);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> canPut[i][j];

	backtracking(0, 0, 0);
	backtracking(1, 0, 1);

	cout << ans[0] + ans[1] << '\n';

	return 0;
}