// Baekjoon02293_Coin1.cpp
// https://www.acmicpc.net/problem/2293
#include <iostream>

using namespace std;

int main(void) {
	ios_base :: sync_with_stdio( false );
	cin.tie( NULL );

	int n, k;
	cin >> n >> k;

	int coins[100];
	int dp[10001] = { 1, };

	for ( int i = 0; i < n; i++ )
		cin >> coins[i];

	for ( int i = 0; i < n; i++ )
		for ( int j = coins[i]; j <= k; j++ )
			dp[j] += dp[j - coins[i]];

	cout << dp[k] << '\n';

	return 0;
}