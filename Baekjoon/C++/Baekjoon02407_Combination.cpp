// Baekjoon02407_Combination.cpp
// https://www.acmicpc.net/problem/2407
#include <iostream>

using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;

	unsigned long long dp[101][101];
	for ( int i = 0; i <= n; i++ ) {
		dp[i][0] = dp[i][i] = 1;
		for ( int j = 1; j < i; j++ )
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
	}

	cout << dp[n][m] << '\n';

	return 0;
}