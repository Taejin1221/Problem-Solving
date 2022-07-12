// Baekjoon23559.cpp
// https://www.acmicpc.net/problem/23559
#include <iostream>

#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;

	pii ans = { 0, x - n * 1'000 }; // { flavor, money }

	int diff[100'000];
	for (int i = 0; i < n; i++) {
		pii menu;
		cin >> menu.first >> menu.second;
		ans.first += menu.second;

		diff[i] = menu.first - menu.second;
	}

	sort(diff, diff + n, greater<int>());
	for (int i = 0; i < n; i++) {
		if (ans.second >= 4'000 && diff[i] > 0) {
			ans.first += diff[i];
			ans.second -= 4'000;
		}
	}

	cout << ans.first << '\n';

	return 0;
}