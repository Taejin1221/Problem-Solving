// LeetCode0650_2KeysKeyboard.cpp
// https://leetcode.com/problems/2-keys-keyboard/

#define INF  1'000'000'000

class Solution {
public:
	int minSteps( int n ) {
		int dp[1'001][1'001];
		for ( int i = 0; i <= n; i++ )
			fill( dp[i], dp[i] + n + 1, INF );

		dp[1][0] = 0;
		dp[1][1] = 1;

		for ( int i = 2; i <= n; i++ ) {
			int minVal = INF;
			for ( int j = 1; j < i; j++ ) {
				dp[i][j] = min( dp[i][j], dp[i - j][j] + 1 );
				minVal = min( minVal, dp[i][j] );
			}

			dp[i][i] = minVal + 1;
		}

		int ans = INF;
		for ( int i = 0; i <= n; i++ )
			ans = min( ans, dp[n][i] );

		return ans;
	}
};