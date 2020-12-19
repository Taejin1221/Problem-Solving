// Baekjoon16194_BuyCard2.cpp
// https://www.acmicpc.net/problem/16194
#include <iostream>
#include <algorithm> /* fill() */

#define INF 1'000'000'000

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int prices[10'001];
	for ( int i = 1; i <= n; i++ )
		cin >> prices[i];

	int dp[1'001];
	fill( dp, dp + n + 1, INF );

	dp[0] = 0;
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= i; j++ ) {
			dp[i] = min( dp[i], dp[i - j] + prices[j] );
		}
	}

	cout << dp[n] << '\n';

	return 0;
}
