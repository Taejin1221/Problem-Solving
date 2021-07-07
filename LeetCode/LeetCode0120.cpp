// LeetCode0120_Triangle.cpp
// https://leetcode.com/problems/triangle/
class Solution {
public:
    int minimumTotal( vector<vector<int>>& triangle ) {
        int n = triangle.size();

        vector<vector<int>> dp;
        dp.push_back( vector<int> ( 1 ) );
        dp[0][0] = triangle[0][0];

        for ( int i = 1; i < n; i++ ) {
            int m = triangle[i].size();
            dp.push_back( vector<int> () );
            dp[i].push_back( dp[i - 1][0] + triangle[i][0] );
            for ( int j = 1; j < m - 1; j++ )
                dp[i].push_back( min( dp[i - 1][j], dp[i - 1][j - 1] ) + triangle[i][j] );
            dp[i].push_back( dp[i - 1][dp[i - 1].size() - 1] + triangle[i][m - 1] );
        }

        int m = triangle[n - 1].size(), ans = 1'000'000'000;
        for ( int i = 0; i < m; i++ )
            ans = min( ans, dp[n - 1][i] );

        return ans;
    }
};