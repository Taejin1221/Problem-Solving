// Baekjoon11727_2xnTiling2.cpp
// https://www.acmicpc.net/problem/11727
#include <iostream>

using namespace std;

int main(void) {
	int dp[1001] = { 0, 1, 3 };

	int n;
	cin >> n;
	for ( int i = 3; i <= n; i++ )
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;

	cout << dp[n] << '\n';

	return 0;
}