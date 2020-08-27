// LeetCode0070_ClimbigStairs.cpp
// https://leetcode.com/problems/climbing-stairs/
class Solution {
public:
	int climbStairs( int n ) {
		int dp[46] = { 0, 1, 2, };

		for ( int i = 3; i <= n; i++ )
			dp[i] = dp[i - 1] + dp[i - 2];

		return dp[n];
	}
};