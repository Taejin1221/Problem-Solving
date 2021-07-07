// LeetCode0064_MinimumPathSum.cpp
// https://leetcode.com/problems/minimum-path-sum/
class Solution {
public:
	int minPathSum( vector<vector<int>>& grid ) {
		vector<vector<int>> dp;
		for ( int i = 0; i < grid.size(); i++ )
			dp.push_back( vector<int> ( grid[i].size() ) );

		for ( int i = 0; i < grid.size(); i++ ) {
			for ( int j = 0; j < grid[i].size(); j++ ) {
				if ( i == 0 && j == 0 )
					dp[i][j] = 0;
				else if ( i == 0 )
					dp[i][j] = dp[i][j - 1];
				else if ( j == 0 )
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = min( dp[i - 1][j], dp[i][j - 1] );
				dp[i][j] += grid[i][j];
			}
		}

		return dp[grid.size() - 1][grid[0].size() - 1];
	}
};
