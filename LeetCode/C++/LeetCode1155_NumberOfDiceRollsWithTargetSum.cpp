// LeetCode1155_NumberOfDiceRollsWithTargetSum.cpp
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
class Solution {
private:
	int DIVISOR = 1'000'000'007;

public:
	int numRollsToTarget( int dice, int face, int target ) {
		int dp[31][1001] = { 0, };

		for ( int i = 1; i <= face; i++ )
			dp[1][i] = 1;

		for ( int i = 2; i <= dice; i++ ) {
			for ( int j = 1; j <= target; j++ ) {
				for ( int k = 1; k < j; k++ ) {
					if ( dp[1][j - k] != 0 ) {
						dp[i][j] += dp[i - 1][k];
						dp[i][j] %= DIVISOR;
					}
				}
			}
		}

		return dp[dice][target];
	}
};