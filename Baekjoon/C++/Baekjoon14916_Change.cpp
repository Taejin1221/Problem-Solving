// Baekjoon14916_Change.cpp
// https://www.acmicpc.net/problem/14916
#include <iostream>
#include <algorithm> /* fill() */

#define INF 100'001

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int dp[100'001];
	fill( dp, dp + n + 1, INF );

	dp[2] = 1, dp[4] = 2, dp[5] = 1;
	for ( int i = 6; i <= n; i++ )
		dp[i] = min( dp[i - 2], dp[i - 5] ) + 1;

	if ( dp[n] >= INF )
		cout << -1;
	else
		cout << dp[n];
	cout << '\n';

	return 0;
}
