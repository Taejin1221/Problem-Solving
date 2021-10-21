// Baekjoon01051.cpp
// https://www.acmicpc.net/problem/1051
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	char rectangle[50][51];
	for (int i = 0; i < n; i++)
		cin >> rectangle[i];

	int ans = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 1; k < 50; k++) {
				if (i + k < n && j + k < m) {
					int me = rectangle[i][j];
					if (rectangle[i + k][j] == me && rectangle[i][j + k] == me && rectangle[i + k][j + k] == me)
						ans = max(ans, k + 1);
				}
			}
		}
	}

	cout << ans * ans << '\n';

	return 0;
}