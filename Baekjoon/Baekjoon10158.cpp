// Baekjoon10158.cpp
// https://www.acmicpc.net/problem/10158
#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
	ll w, h, p, q, t;
	cin >> w >> h >> p >> q >> t;

	ll x_r = (p + t) % (2 * w), y_r = (q + t) % (2 * h);
	ll x_ans = (x_r <= w) ? x_r : 2 * w - x_r, y_ans = (y_r <= h) ? y_r : 2 * h - y_r;
	cout << x_ans << ' ' << y_ans << '\n';

	return 0;
}