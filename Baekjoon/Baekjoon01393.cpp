// Baekjoon01393.cpp
// https://www.acmicpc.net/problem/1393
#include <iostream>

#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;

int GCD(int a, int b) {
	return b ? GCD(b, a % b) : a;
}

int getDistance(pii a, pii b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main(void) {
	pii station;
	cin >> station.x >> station.y;

	pii start; int dx, dy;
	cin >> start.x >> start.y >> dx >> dy;

	pii ans = start;
	int minDistance = getDistance(station, ans);

	if (dx == 0 && dy == 0)
		ans = start;
	else if (dx == 0) {
		int dySign = dy > 0 ? 1 : -1;
		for (int i = start.y; (dySign == 1 && i <= 1'000) || (dySign == -1 && i >= -1'000); i += dySign) {
			pii currPos = { start.x, i };
			if (minDistance > getDistance(station, currPos)) {
				ans = currPos;
				minDistance = getDistance(station, ans);
			}
		}
	} else {
		int gcd = dx > dy ? GCD(dx, dy) : GCD(dy, dx);
		pii gradient = { dx / gcd, dy / gcd };

		int dxSign = dx > 0 ? 1 : -1;
		for (int i = start.x; (dxSign == 1 && i <= 1'000) || (dxSign == -1 && i >= -1'000); i += dxSign * abs(gradient.x)) {
			pii currPos = { i, gradient.y * (i - start.x) / gradient.x + start.y };
			if (minDistance > getDistance(station, currPos)) {
				ans = currPos;
				minDistance = getDistance(station, ans);
			}
		}
	}
	cout << ans.x << ' ' << ans.y << '\n';

	return 0;
}