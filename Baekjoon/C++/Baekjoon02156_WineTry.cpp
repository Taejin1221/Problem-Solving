// Baekjoon02156_WineTry.cpp
// https://www.acmicpc.net/problem/2156
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio( false );
	cin.tie( NULL );

	int dp[2][10000];

	int n;
	cin >> n;

	int nums[10000];
	for ( int i = 0; i < n; i++ )
		cin >> nums[i];

	int maxVal = 0;
	if ( n >= 1 )
		maxVal = dp[0][0] = dp[1][0] = nums[0];
	if ( n >= 2 ) {
		dp[0][1] = nums[1];
		maxVal = dp[1][1] = nums[0] + nums[1];
	}
	if ( n >= 3 ) {
		dp[0][2] = nums[0] + nums[2];
		dp[1][2] = max( nums[0], nums[1] ) + nums[2];

		maxVal = max( dp[1][1], dp[1][2] );
		for ( int i = 3; i < n; i++ ) {
			dp[0][i] = max( dp[1][i - 2], dp[1][i - 3]);
			dp[1][i] = max( dp[0][i - 1], dp[0][i] );

			dp[0][i] += nums[i];
			dp[1][i] += nums[i];

			if ( dp[1][i] > maxVal )
				maxVal = dp[1][i];
		}
	}

	cout << maxVal << '\n';

	return 0;
}