// Baekjoon11006.cpp
// https://www.acmicpc.net/problem/11006
#include <iostream>

using namespace std;

int main(void) {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;


		pair<int, int> ans = { 0, m };
		if (n < m * 2) {
			ans.first = m * 2 - n;
			ans.second = m - ans.first;
		}

		cout << ans.first << ' ' << ans.second << '\n';
	}

	return 0;
}