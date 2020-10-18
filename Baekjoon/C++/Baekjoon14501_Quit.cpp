// Baekjoon14501_Quit.cpp
// https://www.acmicpc.net/problem/14501
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int t[15], p[15];
	for ( int i = 0; i < n; i++ )
		cin >> t[i] >> p[i];

	int maxVal = 0;
	int dp[16] = { 0, };
	for ( int i = 0; i < n; i++ ) {
		dp[i] = max( dp[i - 1], dp[i] );
		if ( i + t[i] <= n ) {
			int temp = dp[i] + p[i];
			dp[i + t[i]] = max( temp, dp[i + t[i]] );
		}
		maxVal = max( maxVal, dp[i] );
	}

	cout << max( maxVal, dp[n] ) << '\n';

	return 0;
}