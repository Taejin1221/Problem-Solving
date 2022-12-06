// Baekjoon17216.cpp
// https://www.acmicpc.net/problem/17216
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int arr[1'000];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ans, dp[1'000] = { 0, };
	dp[n - 1] = ans = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		dp[i] = arr[i];
		for (int j = i; j < n; j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], arr[i] + dp[j]);
		}

		ans = max(ans, dp[i]);
	}

	cout << ans << '\n';
}