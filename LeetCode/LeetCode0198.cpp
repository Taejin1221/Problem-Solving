// LeetCode0198_HouseRobber.cpp
// https://leetcode.com/problems/house-robber/
class Solution {
public:
	int rob( vector<int>& nums ) {
		int size = nums.size();
		if ( size == 0 )
			return 0;

		// 0 row -> Don't use me, 1 row -> Use me
		vector< vector<int> > dp;
		dp.push_back( vector<int> ( size ) );
		dp.push_back( vector<int> ( size ) );

		dp[0][0] = 0;
		dp[1][0] = nums[0];
		for ( int i = 1; i < size; i++ ) {
			dp[0][i] = max( dp[0][i - 1], dp[1][i - 1] );
			dp[1][i] = dp[0][i - 1] + nums[i];
		}

		return max( dp[0][size - 1], dp[1][size - 1] );
	}
};
