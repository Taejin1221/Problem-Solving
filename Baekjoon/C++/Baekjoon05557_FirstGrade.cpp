// Baekjoon05557_FirstGrade.cpp
// https://www.acmicpc.net/problem/5557
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[100];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	long dp[100][21] = { 0, };
	dp[0][arr[0]] = 1;
	for ( int i = 1; i < n - 1; i++ ) {
		for ( int j = 0; j <= 20; j++ ) {
			if ( dp[i - 1][j] ) {
				if ( j + arr[i] <= 20 )
					dp[i][j + arr[i]] += dp[i - 1][j];
				if ( j - arr[i] >= 0 )
					dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}

	cout << dp[n - 2][arr[n - 1]] << '\n';

	return 0;
}