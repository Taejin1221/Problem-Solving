// Baekjoon15989_Plus123IV.cpp
// https://www.acmicpc.net/problem/15989
#include <iostream>

using namespace std;

int main(void) {
	// row 1 -> only 1, row 2 -> 2 under, row 3 -> 3 under
	int dp[4][10'001] = { 0, };
	dp[1][1] = 1;

	dp[1][2] = 1;
	dp[2][2] = 1;

	dp[1][3] = 1;
	dp[2][3] = 1;
	dp[3][3] = 1;

	for ( int i = 4; i <= 10'000; i++ ) {
		dp[1][i] = 1;
		dp[2][i] = dp[1][i - 2] + dp[2][i - 2];
		dp[3][i] = dp[1][i - 3] + dp[2][i - 3] + dp[3][i - 3];
	}

	int t;
	cin >> t;

	while ( t-- ) {
		int n;
		cin >> n;

		cout << dp[1][n] + dp[2][n] + dp[3][n] << '\n';
	}

	return 0;
}
