// Baekjoon01780_2.cpp
// https://www.acmicpc.net/problem/1780
#include <iostream>

using namespace std;

int ans[3] = { 0, };
int n, paper[3'000][3'000];

void solve(int startRow, int startCol, int size) {
	int target = paper[startRow][startCol];
	bool isAllSame = true;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (paper[startRow + i][startCol + j] != target) {
				isAllSame = false;
				break;
			}
		}

		if (!isAllSame)
			break;
	}

	if (isAllSame)
		ans[target + 1]++;
	else {
		int sizeDiv3 = size / 3;
		solve(startRow, startCol, sizeDiv3);
		solve(startRow, startCol + sizeDiv3, sizeDiv3);
		solve(startRow, startCol + sizeDiv3 * 2, sizeDiv3);
		solve(startRow + sizeDiv3, startCol, sizeDiv3);
		solve(startRow + sizeDiv3, startCol + sizeDiv3, sizeDiv3);
		solve(startRow + sizeDiv3, startCol + sizeDiv3 * 2, sizeDiv3);
		solve(startRow + sizeDiv3 * 2, startCol, sizeDiv3);
		solve(startRow + sizeDiv3 * 2, startCol + sizeDiv3, sizeDiv3);
		solve(startRow + sizeDiv3 * 2, startCol + sizeDiv3 * 2, sizeDiv3);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> paper[i][j];

	solve(0, 0, n);

	cout << ans[0] << '\n' << ans[1] << '\n' << ans[2] << '\n';

	return 0;
}