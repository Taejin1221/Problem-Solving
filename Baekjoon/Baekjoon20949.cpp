// Baekjoon20949.cpp
// https://www.acmicpc.net/problem/20949
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

bool compare(pii a, pii b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}

int main(void) {
	int n;
	cin >> n;

	vector<pii> displays;
	for (int i = 1; i <= n; i++) {
		int w, h;
		cin >> w >> h;

		displays.push_back({ w * w + h * h, i });
	}

	sort(displays.begin(), displays.end(), compare);

	for (int i = 0; i < (int)displays.size(); i++)
		cout << displays[i].second << '\n';

	return 0;
}