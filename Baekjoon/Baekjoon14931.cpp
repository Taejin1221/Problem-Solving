// Baekjoon14931.cpp
// https://www.acmicpc.net/problem/14931
#include <iostream>

#include <vector>

using namespace std;

using ll = long long;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> scores;
	for (int i = 0; i < n; i++) {
		int score;
		cin >> score;

		scores.push_back(score);
	}

	pair<int, ll> ans = { 0, 0LL };
	for (int i = 1; i <= n; i++) {
		ll result = 0LL;
		for (int j = i - 1; j < n; j += i)
			result += scores[j];

		if (ans.second < result)
			ans = { i, result };
	}

	cout << ans.first << ' ' << ans.second << '\n';

	return 0;
}