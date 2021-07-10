// Baekjoon14852_Tiling3.cpp
// https://www.acmicpc.net/problem/14852
#include <iostream>

#define MOD 1'000'000'007

using namespace std;

int main(void) {
	int n;
	cin >> n;

	long long sum = 3;
	long long dp[1'000'001] = { 1, 2, 7, };
	for (int i = 3; i <= n; i++) {
		dp[i] = (2 * dp[i - 1] + dp[i - 2] + 2 * sum) % MOD;
		sum = (sum + dp[i - 1]) % MOD;
	}

	cout << dp[n] << '\n';

	return 0;
}