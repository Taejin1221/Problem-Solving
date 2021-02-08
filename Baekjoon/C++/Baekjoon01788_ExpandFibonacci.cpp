// Baekjoon01788_ExpandFibonacci.cpp
// https://www.acmicpc.net/problem/1788
#include <iostream>

#define MOD 1'000'000'000

using namespace std;

int main(void) {
	int n;
	cin >> n;

	if ( n >= 0 ) {
		int dp[1'000'000] = { 0, 1, };
		for ( int i = 2; i <= n; i++ )
			dp[i] = ( dp[i - 1] + dp[i - 2] ) % MOD;

		if ( dp[n] == 0 )
			cout << 0;
		else
			cout << 1;
		cout << '\n';
		cout << dp[n] << '\n';
	} else {
		n *= -1;

		int dp[1'000'000] = { 0, 1, };
		for ( int i = 2; i <= n; i++ )
			dp[i] = ( dp[i - 2] - dp[i - 1] ) % MOD;

		if ( dp[n] < 0 ) {
			cout << -1 << '\n';
			cout << -dp[n] << '\n';
		} else {
			cout << 1 << '\n';
			cout << dp[n] << '\n';
		}
	}

	cout << '\n';

	return 0;
}