// Baekjoon25550.cpp
// https://www.acmicpc.net/problem/25550
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int boxes[1'000][1'000];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> boxes[i][j];

	long long ans = 0LL;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			int small = min(min(boxes[i - 1][j], boxes[i + 1][j]), min(boxes[i][j - 1], boxes[i][j + 1]));
			if (small < boxes[i][j]) {
				if (small != 0)
					ans += small;
			} else
				ans += boxes[i][j] - (boxes[i][j] != 0);
		}
	}

	cout << ans << '\n';

	return 0;
}