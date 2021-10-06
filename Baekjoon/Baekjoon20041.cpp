// Baekjoon20041.cpp
// https://www.acmicpc.net/problem/20041
#include <iostream>

#include <vector>

#define x first
#define y second
#define INF 1'000'000'000
#define ABS(x) (((x) < 0) ? (-(x)) : (x))

using namespace std;

typedef long long ll;
typedef pair<int, int> Coords;

bool escapable(vector<Coords>& polices, Coords target, int distance) {
	for (int i = 0; i < polices.size(); i++) {
		ll policeDistance = (ll)ABS(target.x - polices[i].x) + ABS(target.y - polices[i].y);
		if (policeDistance <= distance)
			return false;
	}

	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int up = -INF, down = INF, left = INF, right = -INF;

	vector<Coords> polices (n);
	for (int i = 0; i < n; i++) {
		cin >> polices[i].x >> polices[i].y;

		up = max(up, polices[i].y);
		down = min(down, polices[i].y);
		right = max(right, polices[i].x);
		left = min(left, polices[i].x);
	}

	Coords thief;
	cin >> thief.x >> thief.y;

	if (up <= thief.y || thief.y <= down || thief.x <= left || right <= thief.x)
		cout << "YES";
	else {
		bool ans = false;

		ans |= escapable(polices, { thief.x, up }, ABS(thief.y - up));
		ans |= escapable(polices, { thief.x, down }, ABS(thief.y - down));
		ans |= escapable(polices, { left, thief.y }, ABS(thief.x - left));
		ans |= escapable(polices, { right, thief.y }, ABS(thief.x - right));

		if (ans)
			cout << "YES";
		else
			cout << "NO";
	}

	cout << '\n';

	return 0;
}