// Baekjoon05631.cpp
// https://www.acmicpc.net/problem/5631
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

struct Position {
	ll x, y;
	Position(): x(0), y(0) { }
	ll getSquareDistance(Position& target) {
		return ((x - target.x) * (x - target.x) + (y - target.y) * (y - target.y));
	}
};

void solveTestcase(int n) {
	vector<Position> houses;
	for (int i = 0; i < n; i++) {
		Position temp;
		cin >> temp.x >> temp.y;

		houses.push_back(temp);
	}

	Position center1, center2;
	cin >> center1.x >> center1.y >> center2.x >> center2.y;
	vector<int> distances[2];
	for (int i = 0; i < n; i++) {
		distances[0].push_back(center1.getSquareDistance(houses[i]));
		distances[1].push_back(center2.getSquareDistance(houses[i]));
	}
	sort(distances[0].begin(), distances[0].end());
	sort(distances[1].begin(), distances[1].end());

	int q;
	cin >> q;

	while (q--) {
		ll r1, r2;
		cin >> r1 >> r2;

		r1 *= r1;
		r2 *= r2;

		int ans = n;
		ans -= upper_bound(distances[0].begin(), distances[0].end(), r1) - distances[0].begin();
		ans -= upper_bound(distances[1].begin(), distances[1].end(), r2) - distances[1].begin();

		cout << max(ans, 0) << '\n';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, t = 1;
	cin >> n;
	while (n) {
		cout << "Case " << t << ":\n";
		solveTestcase(n);

		cin >> n;
		t++;
	}

	return 0;
}