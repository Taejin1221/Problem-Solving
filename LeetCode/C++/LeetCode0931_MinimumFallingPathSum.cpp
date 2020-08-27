// LeetCode0931_MinimumFallingPathSum.cpp
// https://leetcode.com/problems/minimum-falling-path-sum/
class Solution {
public:
	int minFallingPathSum( vector<vector<int>>& A ) {
		int dp[100][100] = { 0, };

		int size = A.size();
		for ( int i = 0; i < size; i++ )
			dp[0][i] = A[0][i];

		for ( int i = 1; i < size; i++ ) {
			for ( int j = 0; j < size; j++ ) {
				dp[i][j] = dp[i - 1][j];
				if ( j != 0 )
					dp[i][j] = min( dp[i - 1][j - 1], dp[i][j] );

				if ( j + 1 != size )
					dp[i][j] = min( dp[i][j], dp[i - 1][j + 1] );

				dp[i][j] += A[i][j];
			}
		}

		int ans = INT_MAX;
		for ( int i = 0; i < size; i++ )
			ans = min( ans, dp[size - 1][i] );

		return ans;
	}
};