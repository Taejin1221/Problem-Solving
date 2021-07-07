// LeetCode0063_UniquePathsII.cpp
// https://leetcode.com/problems/unique-paths-ii/
class Solution {
public:
	int uniquePathsWithObstacles( vector<vector<int>>& grid ) {
		int n = grid.size(), m = grid[0].size();

		if ( grid[0][0] || grid[n - 1][m - 1] )
			return 0;

		int dp[100][100] = { 1, };
		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < m; j++ ) {
				if ( i != 0 && !grid[i - 1][j] )
					dp[i][j] += dp[i - 1][j];

				if ( j != 0 && !grid[i][j - 1] )
					dp[i][j] += dp[i][j - 1];
			}
		}

		return dp[n - 1][m - 1];
	}
};