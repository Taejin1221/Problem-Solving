// Baekjoon10709_Forecaster.cpp
// https://www.acmicpc.net/problem/14852
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	char JOI_map[100][101];
	for (int i = 0; i < n; i++)
		cin >> JOI_map[i];

	int ans[100][100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int time = 0, isFind = 0;
			for (int k = j; k >= 0; k--, time++) {
				if (JOI_map[i][k] == 'c') {
					ans[i][j] = time;
					isFind = 1;
					break;
				}
			}

			if (!isFind)
				ans[i][j] = -1;

			cout << ans[i][j] << ' ';
		}

		cout << '\n';
	}

	return 0;
}