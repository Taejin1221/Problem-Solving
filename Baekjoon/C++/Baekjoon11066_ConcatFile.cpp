// Baekjoon11066_ConcatFile.cpp
// https://www.acmicpc.net/problem/11066
#include <iostream>

using namespace std;

int arr[500];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int k;
		cin >> k;

		int sum[501] = { 0, };
		int dp[501][501] = { 0, };
		for ( int i = 1; i <= k; i++ )
			cin >> arr[i];

		for ( int i = 1; i <= k - 1; i++ )
			dp[i][i + 1] = arr[i] + arr[i + 1];

		for ( int i = 1; i <= k; i++ )
			sum[i] = sum[i - 1] + arr[i];

		for ( int interval = 2; interval <= k - 1; interval++ ) {
			for ( int i = 0; i <= k - interval; i++ ) {
				int r = i, c = i + interval;
				int minVal = 50000001;
				for ( int mid = r; mid < c; mid++ )
					minVal = min( minVal, dp[r][mid] + dp[mid + 1][c] );
				dp[r][c] = minVal + sum[c];
				if ( r > 0 )
				 dp[r][c] -= sum[r - 1];
			}
		}
		cout << dp[1][k] << '\n';
	}

	return 0;
}