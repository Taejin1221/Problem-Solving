// Baekjoon20917.cpp
// https://www.acmicpc.net/problem/20917
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int n;
int distances[200'000];

int check(ll target) {
	int ans = 1, prev = distances[0];
	for (int i = 1; i < n; i++) {
		if (distances[i] - prev >= target) {
			ans++;
			prev = distances[i];
		}
	}

	return ans;
}

void solveTestcase() {
	int s;
	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> distances[i];
	sort(distances, distances + n);

	ll left = 1, right = 1'000'000'000;
	while (left < right - 1) {
		ll mid = (left + right) / 2;
		if (check(mid) < s) {
			right = mid;
		} else {
			left = mid;
		}
	}

	cout << left << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		solveTestcase();
	}

	return 0;
}
