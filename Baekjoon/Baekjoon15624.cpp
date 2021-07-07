// Baekjoon15624_Fibonacci7.cpp
// https://www.acmicpc.net/problem/15624
#include <iostream>

#define MOD 1'000'000'007

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int dp[1'000'001] = { 0, 1, 1, };
	for ( int i = 3; i <= n; i++ )
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	cout << dp[n] << '\n';

	return 0;
}