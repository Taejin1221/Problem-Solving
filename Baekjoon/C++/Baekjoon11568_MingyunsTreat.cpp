// Baekjoon11568_MingyunsTreat.cpp
// https://www.acmicpc.net/problem/11568
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[1'000];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ans = 1, dp[1'000];
	fill(dp, dp + n, 1);

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j < n; j++) {
			if (arr[i] < arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}

		ans = max(ans, dp[i]);
	}

	cout << ans << '\n';

	return 0;
}