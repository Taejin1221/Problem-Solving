// Baekjoon01660.cpp
// https://www.acmicpc.net/problem/1660
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int tetrahedon[122] = { 0, 1, };
	int i = 2;
	while (tetrahedon[i - 1] <= n) {
		tetrahedon[i] = tetrahedon[i - 1] + i * (i + 1) / 2;
		i++;
	}

	int maxIdx = 1;
	int dp[300'001] = { 0, };

	fill(dp + 1, dp + n + 1, 1'234'567'890);
	for (int i = 1; i <= n; i++) {
		if (tetrahedon[maxIdx] <= i)
			maxIdx++;

		for (int j = 1; j < maxIdx; j++) {
			dp[i] = min(dp[i], dp[i - tetrahedon[j]] + 1);
		}		
	}

	cout << dp[n] << '\n';

	return 0;
}