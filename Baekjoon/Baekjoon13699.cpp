// Baekjoon13699_RecurrenceFormula.cpp
// https://www.acmicpc.net/problem/13699
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	long long dp[36] = { 1, };

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
			dp[i] += dp[j] * dp[i - j - 1];

	cout << dp[n] << '\n';

	return 0;
}