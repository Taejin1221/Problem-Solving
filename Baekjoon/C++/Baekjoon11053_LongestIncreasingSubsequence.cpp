// Baekjoon11053_LongestIncreasingSubsequence.cpp
// https://www.acmicpc.net/problem/11053
#include <iostream>

using namespace std;

int main(void) {
	ios_base :: sync_with_stdio( false );
	cin.tie( NULL );

	int n, maxVal = 1;
	int dp[1000];
	int arr[1000];

	cin >> n;
	for ( int i = 0; i < n; i++ ) {
		cin >> arr[i];
		dp[i] = 1;
	}
	
	for ( int i = n - 2; i >= 0; i-- ) {
		for ( int j = i + 1; j < n; j++ ) {
			if ( arr[j] > arr[i]) {
				if ( dp[j] + 1 > dp[i] )
					dp[i] = dp[j] + 1;
			}
		}
		maxVal = maxVal < dp[i] ? dp[i] : maxVal;
	}

	cout << maxVal << '\n';

	return 0;
}