// Baekjoon02723.cpp
// https://www.acmicpc.net/problem/2723
#include <iostream>

using namespace std;

using ll = long long;

ll solve(int n) {
	int dp[12][2'048] = { { 0, } };

	int max2n = 1 << n;
	for (int i = 1; i < max2n; i++) {
		dp[1][i] = 1;
	}

	ll ans = max2n - 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < max2n; j++) {
			for (int k = 1; k < max2n; k++) {
				if ((j & k) == 0) {
					dp[i][j | k] += dp[i - 1][k];
					ans += dp[i - 1][k];
				}
			}
		}
	}

	return ans;
}

int main(void) {
	ll answers[12] = { 0, };

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		if (answers[n] == 0)
			answers[n] = solve(n);

		cout << answers[n] << '\n';
	}

	return 0;
}