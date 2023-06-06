// Baekjoon20115.cpp
// https://www.acmicpc.net/problem/20115
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> drink;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		drink.push_back(temp);
	}

	sort(drink.begin(), drink.end(), greater<int>());

	double ans = drink[0];
	for (int i = 1; i < (int)drink.size(); i++) {
		ans += drink[i] / 2.0;
	}

	cout << ans << '\n';

	return 0;
}