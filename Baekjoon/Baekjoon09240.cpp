// Baekjoon09240.cpp
// https://www.acmicpc.net/problem/9240
#include <cstdio>

#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Coordinate {
	int x, y;
	Coordinate(): x(0), y(0) { }
	Coordinate(int x, int y): x(x), y(y) { }
	Coordinate operator-(Coordinate& c2) {
		return Coordinate(x - c2.x, y - c2.y);
	}
};

Coordinate coords[100'000];

int getCCW(Coordinate& a, Coordinate& b, Coordinate& c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool compare1(Coordinate& c1, Coordinate& c2) {
	return (c1.y != c2.y) ? c1.y < c2.y : c1.x < c2.x;
}

bool compare2(Coordinate& c1, Coordinate& c2) {
	int ccw = getCCW(coords[0], c1, c2);
	if (ccw != 0)
		return 0 < ccw;
	else
		return compare1(c1, c2);
}

int getDistance(Coordinate& c1, Coordinate& c2) {
	return (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y);
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &coords[i].x, &coords[i].y);

	sort(coords, coords + n, compare1);
	sort(coords + 1, coords + n, compare2);

	vector<Coordinate> stck;
	stck.push_back(coords[0]);
	stck.push_back(coords[1]);

	for (int i = 2; i < n; i++) {
		while (stck.size() >= 2) {
			Coordinate prev = stck.back(); stck.pop_back();
			Coordinate prevprev = stck.back();

			if (getCCW(prevprev, prev, coords[i]) > 0) {
				stck.push_back(prev);
				break;
			}
		}

		stck.push_back(coords[i]);
	}

	n = stck.size();

	int leftIdx = 0, rightIdx = 0;
	for (int i = 1; i < n; i++) {
		if (stck[i].x < stck[leftIdx].x)
			leftIdx = i;
		if (stck[rightIdx].x < stck[i].x)
			rightIdx = i;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, getDistance(stck[leftIdx], stck[rightIdx]));
		Coordinate a = stck[(leftIdx + 1) % n] - stck[leftIdx];
		Coordinate b = stck[rightIdx] - stck[(rightIdx + 1) % n];

		Coordinate base = Coordinate();
		int ccw = getCCW(base, a, b);
		if (ccw > 0)
			leftIdx = (leftIdx + 1) % n;
		else
			rightIdx = (rightIdx + 1) % n;
	}

	printf("%.6lf\n", sqrt((double)ans));

	return 0;
}