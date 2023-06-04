// Baekjoon09063.cpp
// https://www.acmicpc.net/problem/9063
#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int left = 10'000, right = -10'000, top = -10'000, bottom = 10'000;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		left = min(left, x);
		right = max(right, x);
		top = max(top, y);
		bottom = min(bottom, y);
	}

	cout << (right - left) * (top - bottom) << '\n';

	return 0;
}