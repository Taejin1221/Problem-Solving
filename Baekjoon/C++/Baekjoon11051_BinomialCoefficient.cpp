// Baekjoon11051_BinomialCoefficient.cpp
// https://www.acmicpc.net/problem/11051
#include <iostream>

using namespace std;

int main(void) {
	int dp[1001][1001];
	dp[0][0] = 0;
	dp[1][0] = dp[1][1] = 1;

	int n, k;
	cin >> n >> k;

	for ( int i = 0; i <= n; i++ ) {
		for ( int j = 1; j < i; j++ ) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
		dp[i][0] = dp[i][i] = 1;
	}

	cout << dp[n][k] << '\n';

	return 0;
}