// LeetCode1143_LongestCommonSubsequence.cpp
// https://leetcode.com/problems/longest-common-subsequence/
class Solution {
public:
	int longestCommonSubsequence( string text1, string text2 ) {
		int size1 = text1.size(), size2 = text2.size();

		int dp[1000][1000];
		for ( int i = 0; i < size1; i++ ) {
			for ( int j = 0; j < size2; j++ ) {
				if ( text1[i] == text2[j] ) {
					if ( !i || !j )
						dp[i][j] = 1;
					else
						dp[i][j] = dp[i - 1][j - 1] + 1;
				} else {
					if ( !i && !j )
						dp[i][j] = 0;
					else if ( !i )
						dp[i][j] = dp[i][j - 1];
					else if ( !j )
						dp[i][j] = dp[i - 1][j];
					else
						dp[i][j] = max( dp[i - 1][j - 1], max( dp[i - 1][j], dp[i][j - 1] ) );
				}
			}
		}

		return dp[size1 - 1][size2 - 1];
	}
};