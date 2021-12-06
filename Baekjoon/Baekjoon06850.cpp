// Baekjoon06850.cpp
// https://www.acmicpc.net/problem/6850
#include <iostream>

#include <vector>
#include <algorithm>

#define X first
#define Y second
#define ABS(x) (((x) < 0) ? (-x) : (x))

using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

pii bottomLeft;

ll getCCW(pii a, pii b, pii c) {
	return ((b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X));
}

ll getSquareDistance(pii a, pii b) {
	return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
}

bool compare(pii a, pii b) {
	ll ccw = getCCW(bottomLeft, a, b);
	if (ccw != 0)
		return ccw > 0;
	else
		return getSquareDistance(bottomLeft, a) < getSquareDistance(bottomLeft, b);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	pii positions[10'000];

	int bottomLeftIdx = 0;
	for (int i = 0; i < n; i++) {
		cin >> positions[i].X >> positions[i].Y;
		if (positions[i].X < positions[bottomLeftIdx].X)
			bottomLeftIdx = i;
		else if (positions[i].X == positions[bottomLeftIdx].X && positions[i].Y < positions[bottomLeftIdx].Y)
			bottomLeftIdx = i;
	}

	bottomLeft = positions[bottomLeftIdx];
	positions[bottomLeftIdx] = positions[0];
	positions[0] = bottomLeft;

	sort(positions + 1, positions + n, compare);

	vector<pii> stck;
	stck.push_back(positions[0]);
	stck.push_back(positions[1]);
	for (int i = 2; i < n; i++) {
		while (stck.size() >= 2) {
			pii top = stck.back(); stck.pop_back();
			if (getCCW(stck.back(), top, positions[i]) > 0) {
				stck.push_back(top);
				break;
			}
		}
		stck.push_back(positions[i]);
	}

	ll ans = 0LL;
	for (int i = 1; i < stck.size() - 1; i++)
		ans += getCCW(stck[0], stck[i], stck[i + 1]);
	ans /= 2LL;

	cout << ans / 50 << '\n';

	return 0;
}