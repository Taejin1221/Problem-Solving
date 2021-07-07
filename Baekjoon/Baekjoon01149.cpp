// Baekjoon01149_RGBDistance.cpp
// https://www.acmicpc.net/problem/1149
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int rgb[3][1'000];
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < 3; j++ )
			cin >> rgb[j][i];

	int dp[3][1'000] = { 0, };
	dp[0][0] = rgb[0][0];
	dp[1][0] = rgb[1][0];
	dp[2][0] = rgb[2][0];

	for ( int i = 1; i < n; i++ ) {
		dp[0][i] = min( dp[1][i - 1], dp[2][i - 1] ) + rgb[0][i];
		dp[1][i] = min( dp[0][i - 1], dp[2][i - 1] ) + rgb[1][i];
		dp[2][i] = min( dp[0][i - 1], dp[1][i - 1] ) + rgb[2][i];
	}

	cout << min( dp[0][n - 1], min( dp[1][n - 1], dp[2][n - 1] ) ) << '\n';

	return 0;
}