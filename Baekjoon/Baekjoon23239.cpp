// Baekjoon23239.cpp
// https://www.acmicpc.net/problem/23239
#include <iostream>

using namespace std;

typedef long long ll;

ll getDotNumber(ll r) {
	ll ans = 0ll, y = r;
	for (ll x = 1; x < r; x++) {
		while (x * x + y * y > r * r)
			y--;
		ans += y;
	}

	return ans;
}

ll getDotNumber(ll r, ll r1, ll r2, ll targetX, ll targetY) {
	ll ans = 0ll, y = r;
	for (ll x = 1; x < r; x++) {
		ll disX = x + targetX, disY = y + targetY;
		while ((disX * disX + y * y > r1 * r1) || (disY * disY + x * x > r2 * r2)) {
			y--;
			disY = y + targetY;
		}
		ans += y;
	}

	return ans;
}

int main(void) {
	int w, h, l;
	cin >> w >> h >> l;

	ll ans = 0ll;
	ans += getDotNumber(l) * 3 + l * 2;
	if (l > w)
		ans += getDotNumber(l - w) + (l - w);

	if (l > h)
		ans += getDotNumber(l - h) + (l - h);

	if (l > w + h)
		ans -= getDotNumber(l - w - h, l - h, l - w, w, h);

	cout << ans << '\n';

	return 0;
}