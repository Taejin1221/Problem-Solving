// Baekjoon04811_Pills.cpp
// https://www.acmicpc.net/problem/4811
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long dp[31][31] = { 0, };
	dp[1][0] = dp[1][1] = 1;

	for ( int i = 2; i <= 30; i++ ) {
		dp[i][i] = 1;
		for ( int j = i - 1; j >= 1; j-- )
			dp[i][j] = dp[i][j + 1] + dp[i - 1][j - 1];
		dp[i][0] = dp[i][1];
	}

	int n;
	cin >> n;
	while ( n ) {
		cout << dp[n][0] << '\n';

		cin >> n;
	}

	return 0;
}