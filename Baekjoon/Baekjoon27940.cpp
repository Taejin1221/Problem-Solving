// Baekjoon27940.cpp
// https://www.acmicpc.net/problem/27940
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	int rain = 0, day = 0;

	bool isBreak = false;
	while (day < m) {
		day++;

		int t, r;
		cin >> t >> r;

		rain += r;
		if (rain > k) {
			isBreak = true;
			break;
		}
	}

	if (!isBreak)
		cout << -1;
	else
		cout << day << ' ' << 1;
	cout << '\n';

	return 0;
}