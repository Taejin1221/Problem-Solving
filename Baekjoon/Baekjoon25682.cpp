// Baekjoon25682.cpp
// https://www.acmicpc.net/problem/25682
#include <iostream>

using namespace std;

#define MAX 2'001

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	char board[MAX][MAX];
	int prefixSum[2][MAX][MAX] = { { { 0, }, }, }; // b, w
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			prefixSum[0][i + 1][j + 1] = prefixSum[0][i + 1][j] + prefixSum[0][i][j + 1] - prefixSum[0][i][j];
			prefixSum[1][i + 1][j + 1] = prefixSum[1][i + 1][j] + prefixSum[1][i][j + 1] - prefixSum[1][i][j];

			char compare = (i + j) % 2 == 0 ? 'W' : 'B';
			(board[i][j] == compare) ? prefixSum[0][i + 1][j + 1]++ : prefixSum[1][i + 1][j + 1]++;
		}
	}

	int ans = n * m;
	for (int i = 0; i <= n - k; i++) {
		for (int j = 0; j <= m - k; j++) {
			for (int bw = 0; bw < 2; bw++) {
				int result = prefixSum[bw][i + k][j + k] - prefixSum[bw][i][j + k] - prefixSum[bw][i + k][j] + prefixSum[bw][i][j];
				ans = min(ans, result);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}