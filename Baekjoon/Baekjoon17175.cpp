// Baekjoon17175_BoringFibonacci.cpp
// https://www.acmicpc.net/problem/17175
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	long dp[51] = { 1, 1, };
	for (int i = 2; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2] + 1) % 1'000'000'007;

	cout << dp[n] << '\n';

	return 0;
}