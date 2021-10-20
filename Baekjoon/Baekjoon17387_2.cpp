// Baekjoon17387_2.cpp
#include <iostream>

using namespace std;

typedef long long ll;

struct Point {
	ll x, y;
	Point(): x(0), y(0) { }
	bool isInMiddleOf(Point& target1, Point& target2) const {
		ll smallX = target1.x < target2.x ? target1.x : target2.x;
		ll bigX = target1.x > target2.x ? target1.x : target2.x;
		ll smallY = target1.y < target2.y ? target1.y : target2.y;
		ll bigY = target1.y > target2.y ? target1.y : target2.y;

		return (smallX <= x && x <= bigX) && (smallY <= y && y <= bigY);
	}
};

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

	if (c1 * c2 == 0 && c3 * c4 == 0) {
		if (b1.isInMiddleOf(a1, a2) || b2.isInMiddleOf(a1, a2) || a1.isInMiddleOf(b1, b2) || a2.isInMiddleOf(b1, b2))
			return true;
	} else if (c1 * c2 <= 0 && c3 * c4 <= 0)
		return true;
	return false;
}

int main(void) {
	Point a1, a2, b1, b2;
	cin >> a1.x >> a1.y >> a2.x >> a2.y;
	cin >> b1.x >> b1.y >> b2.x >> b2.y;


	if (isIntersect(a1, a2, b1, b2))
		cout << 1;
	else
		cout << 0;
	cout << endl;

	return 0;
}