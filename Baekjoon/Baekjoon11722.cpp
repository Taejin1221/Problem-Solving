// Baekjoon11722_LongestDecreasingSubsequence.cpp
// https://www.acmicpc.net/problem/11722
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[1000];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	int ans = 0;
	int dp[1000] = { 0, };
	for ( int i = n - 1; i >= 0; i-- ) {
		dp[i] = 1;
		for ( int j = i + 1; j < n; j++ ) {
			if ( arr[j] < arr[i] )
				dp[i] = max( dp[i], dp[j] + 1 );
		}
		ans = max( ans, dp[i] );
	}

	cout << ans << '\n';

	return 0;
}