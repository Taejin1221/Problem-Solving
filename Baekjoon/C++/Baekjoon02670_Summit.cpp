// Baekjoon02670_Summit.cpp
// https://www.acmicpc.net/problem/1670
#include <iostream>

#define DIVISOR 987654321

using namespace std;

int main(void) {
	int n;
	cin >> n;

	long dp[10'001] = { 1, 0, 1, 0, 2, };
	if ( n == 2 )
		cout << dp[2];
	else if ( n == 4 )
		cout << dp[4];
	else {
		for ( int i = 6; i <= n; i += 2 ) {
			for ( int j = 2; j <= i; j += 2 ) {
				dp[i] += ( dp[i - j] * dp[j - 2] ) % DIVISOR;
				dp[i] %= DIVISOR;
			}
		}
		cout << dp[n];
	}
	cout << '\n';

	return 0;
}