// Baekjoon09711.cpp
// https://www.acmicpc.net/problem/9711
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int p, q;
		cin >> p >> q;
		long long dp[10'001] = { 0, 1, 1, };
		for (int i = 3; i <= p; i++)
			dp[i] = (dp[i - 1] + dp[i - 2]) % q;

		cout << "Case #" << i << ": " << dp[p] % q << '\n';
	}

	return 0;
}