// LeetCode0096_UniqueBinarySearchTrees.cpp
// https://leetcode.com/problems/unique-binary-search-trees/
class Solution {
public:
	int numTrees( int n ) {
		int dp[20] = { 1, 1, 2 };
		for ( int i = 3; i <= n; i++ )
			for ( int j = 0; j < i; j++ )
				dp[i] += dp[i - j - 1] * dp[j];

		return dp[n];
	}
};