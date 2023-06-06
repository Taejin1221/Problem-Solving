// Baekjoon19953.cpp
// https://www.acmicpc.net/problem/19953
#include <iostream>

using namespace std;

int main(void) {
	int v0, m, t;
	cin >> v0 >> m >> t;

	int v1 = v0 * m % 10, v2 = v1 * m % 10, v3 = v2 * m % 10, v4 = v3 * m % 10;

	int n = (t - 1) / 4;
	pair<int, int> ans;
	if (t % 4 == 1)
		ans = { n * (v1 - v3), v0 + n * (v4 - v2) };
	else if (t % 4 == 2)
		ans = { n * (v1 - v3) + v1, v0 + n * (v4 - v2) };
	else if (t % 4 == 3)
		ans = { n * (v1 - v3) + v1, v0 + n * (v4 - v2) - v2 };
	else if (t % 4 == 0)
		ans = { n * (v1 - v3) + v1 - v3, v0 + n * (v4 - v2) - v2 };

	cout << ans.first << ' ' << ans.second << '\n';

	return 0;
}