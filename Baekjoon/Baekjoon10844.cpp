// Baekjoon10844_SimpleStepNumber.cpp
// https://www.acmicpc.net/problem/10844
#include <iostream>

#define DIVISOR 1'000'000'000

using namespace std;

int main(void) {
	int n;
	cin >> n;

	long long dp[101][10] = { 0, };

	for ( int i = 1; i < 10; i++ )
		dp[1][i] = 1;

	for ( int i = 2; i <= n; i++ ) {
		dp[i][0] = dp[i - 1][1];
		for ( int j = 1; j <= 8; j++ ) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]);
			dp[i][j] %= DIVISOR;
		}
		dp[i][9] = dp[i - 1][8];
	}

	long long sum = 0;
	for ( int i = 0; i < 10; i++ )
		sum += dp[n][i];
	sum %= DIVISOR;

	cout << sum << '\n';

	return 0;
}