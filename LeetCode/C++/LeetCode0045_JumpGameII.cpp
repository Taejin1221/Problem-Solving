// LeetCode0045_JumpGameII.cpp
// https://leetcode.com/problems/jump-game-ii/
#define INF 1'000'000'000

class Solution {
public:
	int jump( vector<int> nums ) {
		int n = nums.size();

		int dp[1'000] ;
		fill( dp, dp + n, INF );

		dp[0] = 0;
		for ( int i = 0; i < nums.size(); i++ )	{
			for ( int j = 1; j <= min( nums[i], n - i ); j++ )
				if ( i + j < n )
					dp[i + j] = min( dp[i + j], dp[i] + 1 );
		}

		return dp[n - 1];
	}
};