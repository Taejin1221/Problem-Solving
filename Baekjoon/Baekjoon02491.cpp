// Baekjoon02491_Sequence.cpp
// https://www.acmicpc.net/problem/2491
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int prev, dp[2][100'000] = { 0, };
	cin >> prev;

	int ans = 1;
	dp[0][0] = 1, dp[1][0] = 1;
	for ( int i = 1; i < n; i++ ) {
		int curr;
		cin >> curr;

		if ( prev == curr ) {
			dp[0][i] = dp[0][i - 1] + 1;
			dp[1][i] = dp[1][i - 1] + 1;
		} else if ( prev < curr ) {
			dp[0][i] = dp[0][i - 1] + 1;
			dp[1][i] = 1;
		} else {
			dp[0][i] = 1;
			dp[1][i] = dp[1][i - 1] + 1;
		}

		ans = max( ans, max( dp[0][i], dp[1][i] ) );

		prev = curr;
	}

	cout << ans << '\n';

	return 0;
}