// Baekjoon18353_ArrangeSoldiers.cpp
// https://www.acmicpc.net/problem/18353
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int power[2'000];
	for (int i = 0; i < n; i++)
		cin >> power[i];

	int dp[2'000];
	fill(dp, dp + n, 1);

	int maxRemainSolders = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j < n; j++)
			if (power[i] > power[j])
				dp[i] = max(dp[i], dp[j] + 1);

		maxRemainSolders = max(maxRemainSolders, dp[i]);
	}

	cout << n - maxRemainSolders << '\n';

	return 0;
}