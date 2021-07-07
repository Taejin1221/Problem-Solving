// Baekjoon13301_TileDecoration.cpp
// https://www.acmicpc.net/problem/13301
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	long dp[81] = { 0, 1, 1, };
	for ( int i = 3; i <= n; i++ )
		dp[i] = dp[i - 1] + dp[i - 2];

	cout << (dp[n] + dp[n - 1]) * 2 + dp[n] * 2 << '\n';

	return 0;
}