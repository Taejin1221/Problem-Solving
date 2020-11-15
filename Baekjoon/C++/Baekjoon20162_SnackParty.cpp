// Baekjoon20162_SnackParty.cpp
// https://www.acmicpc.net/problem/20162
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int arr[1000];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	int dp[1000], ans = 0;
	for ( int i = n - 1; i >= 0; i-- ) {
		dp[i] = arr[i];
		for ( int j = i + 1; j < n; j++ ) {
			if ( arr[i] < arr[j] ) {
				dp[i] = max( dp[i], arr[i] + dp[j] );
			}
		}

		ans = max( ans, dp[i] );
	}

	cout << ans << '\n';

	return 0;
}