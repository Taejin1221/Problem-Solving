// Baekjoon09465_Sticker.cpp
// https://www.acmicpc.net/problem/9465
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int arr[2][100'000];
	while ( t-- ) {
		int n;
		cin >> n;

		for ( int i = 0; i < 2; i++ )
			for ( int j = 0; j < n; j++ )
				cin >> arr[i][j];

		int dp[2][2][100'000] = { 0, };
		dp[0][0][0] = arr[0][0];
		dp[0][1][0] = arr[1][0];

		dp[1][0][0] = arr[1][0];
		dp[1][1][0] = arr[0][0];

		for ( int i = 1; i < n; i++ ) {
			dp[0][0][i] = dp[1][0][i - 1] + arr[0][i];
			dp[0][1][i] = dp[1][1][i - 1] + arr[1][i];

			int prevSticker = max( dp[0][0][i - 1], dp[0][1][i - 1] );
			dp[1][0][i] = max( prevSticker, dp[0][1][i] );
			dp[1][1][i] = max( prevSticker, dp[0][0][i] );
		}

		int ans = max( dp[1][0][n - 1], dp[1][1][n - 1] );
		cout << ans << '\n';
	}

	return 0;
}