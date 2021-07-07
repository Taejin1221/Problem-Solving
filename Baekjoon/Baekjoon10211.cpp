// Baekjoon10211_MaximumSubarray.cpp
// https://www.acmicpc.net/problem/10211
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int n;
		cin >> n;

		int arr[1000];
		for ( int i = 0; i < n; i++ )
			cin >> arr[i];

		int maxVal = arr[0];
		long dp[1000] = { arr[0], };
		for ( int i = 1; i < n; i++ ) {
			if ( dp[i - 1] > 0 )
				dp[i] += dp[i - 1] + arr[i];
			else
				dp[i] = arr[i];
			maxVal = ( maxVal < dp[i] ) ? dp[i] : maxVal;
		}

		cout << maxVal << '\n';
	}

	return 0;
}