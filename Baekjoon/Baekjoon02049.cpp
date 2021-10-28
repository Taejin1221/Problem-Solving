// Baekjoon02049.cpp
// https://www.acmicpc.net/problem/2049
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

struct Point {
	int x, y;
	Point(): x(0), y(0) { }
	Point(int x, int y): x(x), y(y) { }
	Point operator-(const Point& p2) const {
		return Point(x - p2.x, y - p2.y);
	}
};

Point bottomLeft;

int getCCW(Point& a, Point& b, Point& c) {
	return ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));
}

int getSquareDistance(Point& a, Point& b) {
	return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool compare(Point& p1, Point& p2) {
	int ccw = getCCW(bottomLeft, p1, p2);
	if (ccw != 0)
		return ccw > 0;
	else
		return getSquareDistance(bottomLeft, p1) < getSquareDistance(bottomLeft, p2);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int bottomLeftIdx = 0;
	Point arr[100'000];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
		if (arr[i].y < arr[bottomLeftIdx].y)
			bottomLeftIdx = i;
		else if (arr[i].y == arr[bottomLeftIdx].y && arr[i].x < arr[bottomLeftIdx].x)
			bottomLeftIdx = i;
	}

	Point temp = arr[bottomLeftIdx];
	arr[bottomLeftIdx] = arr[0];
	bottomLeft = arr[0] = temp;

	sort(arr + 1, arr + n, compare);

	vector<Point> stck;
	stck.push_back(arr[0]);
	stck.push_back(arr[1]);
	for (int i = 2; i < n; i++) {
		while (stck.size() >= 2) {
			Point prev = stck.back(); stck.pop_back();
			if (getCCW(stck.back(), prev, arr[i]) > 0) {
				stck.push_back(prev);
				break;
			}
		}

		stck.push_back(arr[i]);
	}

	n = stck.size();
	int left = 0, right = 0;
	for (int i = 0; i < n; i++) {
		if (stck[i].x < stck[left].x)
			left = i;
		if (stck[right].x < stck[i].x)
			right = i;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, getSquareDistance(stck[left], stck[right]));

		Point p1 = stck[(left + 1) % n] - stck[left];
		Point p2 = stck[right] - stck[(right + 1) % n];

		Point base = Point();
		if (getCCW(base, p1, p2) >= 0)
			left = (left + 1) % n;
		else
			right = (right + 1) % n;
	}

	cout << ans << '\n';

	return 0;
}