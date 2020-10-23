// Baekjooon11055_LargestIncreasingSubsequence.cpp
// https://www.acmicpc.net/problem/11055
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[1'000];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	int ans = 0;
	int dp[1'000] = { 0, };
	for ( int i = n - 1; i >= 0; i-- ) {
		dp[i] = arr[i];
		for ( int j = i + 1; j < n; j++ ) {
			if ( arr[i] < arr[j] )
				dp[i] = max( dp[i], arr[i] + dp[j] );
		}

		ans = max( ans, dp[i] );
	}

	cout << ans << '\n';

	return 0;
}