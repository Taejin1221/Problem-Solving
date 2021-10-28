// Baekjoon23247.cpp
// https://www.acmicpc.net/problem/23247
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int map[301][301] = { { 0, }, };
	int rowSum[301][301] = { { 0, }, }, colSum[301][301] = { { 0, }, };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			rowSum[i][j] = rowSum[i][j - 1] + map[i][j];
			colSum[i][j] = colSum[i - 1][j] + map[i][j];
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 10) {
				ans++;
			} else {
				int sum = map[i][j];

				int startRow = i, startCol = j;
				while (sum <= 10 && (startRow > 0 && startCol > 0)) {
					int prevSum = sum, prevRow = startRow, prevCol = startCol;
					while (sum < 10 && startCol > 0) {
						sum += colSum[i][startCol - 1] - colSum[startRow - 1][startCol - 1];
						if (sum == 10)
							ans++;
						startCol--;
					}
					startCol = prevCol;

					sum = prevSum;
					while (sum < 10 && startRow > 0) {
						sum += rowSum[startRow - 1][j] - rowSum[startRow - 1][startCol - 1];
						if (sum == 10)
							ans++;
						startRow--;
					}
					startRow = prevRow;
					sum = prevSum;

					if (startRow > 1 && startCol > 1) {
						startRow = prevRow, startCol = prevCol;
						sum += (rowSum[startRow - 1][j] - rowSum[startRow - 1][startCol - 2]) + (colSum[i][startCol - 1] - colSum[startRow - 2][startCol - 1]) - map[startRow - 1][startCol - 1];
						if (sum == 10)
							ans++;
					}

					startRow--, startCol--;
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}