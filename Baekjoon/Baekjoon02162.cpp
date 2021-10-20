// Baekjoon02162.cpp
// https://www.acmicpc.net/problem/2162
#include <iostream>

using namespace std;

typedef long long ll;

struct Point {
	ll x, y;
	Point(): x(0), y(0) { }
	bool isInMiddle(Point& target1, Point& target2) const {
		ll smallX = target1.x < target2.x ? target1.x : target2.x, bigX = target1.x > target2.x ? target1.x : target2.x;
		ll smallY = target1.y < target2.y ? target1.y : target2.y, bigY = target1.y > target2.y ? target1.y : target2.y;

		return (smallX <= x && x <= bigX) && (smallY <= y && y <= bigY);
	}
};

int parent[3'000];

int getCCWSign(Point& p1, Point& p2, Point& p3) {
	ll ccw = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
	if (ccw < 0)
		return -1;
	else if (ccw > 0)
		return 1;
	else
		return 0;
}

bool isIntersect(Point& a1, Point& a2, Point& b1, Point& b2) {
	int c1 = getCCWSign(a1, a2, b1), c2 = getCCWSign(a1, a2, b2);
	int c3 = getCCWSign(b1, b2, a1), c4 = getCCWSign(b1, b2, a2);

	if (c1 * c2 < 0 && c3 * c4 < 0)
		return true;
	else if ((c1 * c2 == 0 && c3 * c4 < 0) || (c1 * c2 < 0 && c3 * c4 == 0))
		return true;
	else if (c1 * c2 == 0 && c3 * c4 == 0)
		if (b1.isInMiddle(a1, a2) || b2.isInMiddle(a1, a2) || a1.isInMiddle(b1, b2) || a2.isInMiddle(b1, b2))
			return true;
	return false;
}

int getRoot(int target) {
	if (target == parent[target])
		return target;
	else
		return parent[target] = getRoot(parent[target]);
}

void Union(int a, int b) {
	int aRoot = getRoot(a), bRoot = getRoot(b);

	if (aRoot < bRoot)
		parent[bRoot] = aRoot;
	else
		parent[aRoot] = bRoot;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	pair<Point, Point> lines[3'000];
	for (int i = 0; i < n; i++) {
		cin >> lines[i].first.x >> lines[i].first.y >> lines[i].second.x >> lines[i].second.y;
		parent[i] = i;
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (isIntersect(lines[i].first, lines[i].second, lines[j].first, lines[j].second))
				Union(i, j);
		}
	}

	int group[3'000] = { 0, };
	for (int i = 0; i < n; i++)
		group[getRoot(i)]++;

	pair<int, int> ans = { 0, 0 };
	for (int i = 0; i < n; i++) {
		if (group[i])
			ans.first++, ans.second = max(ans.second, group[i]);
	}

	cout << ans.first << '\n' << ans.second << '\n';

	return 0;
}