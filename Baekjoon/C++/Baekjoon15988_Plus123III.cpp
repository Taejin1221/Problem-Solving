// Baekjoon15988_Plus123III.cpp
// https://www.acmicpc.net/problem/15988
#include <iostream>

#define MAX 1'000'001
#define MOD 1'000'000'009

using namespace std;

int main(void) {
	long long dp[MAX] = { 0, };
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for ( int i = 4; i < MAX; i++ )
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;

	int t;
	cin >> t;

	while ( t-- ) {
		int n;
		cin >> n;

		cout << dp[n] << '\n';
	}

	return 0;
}
