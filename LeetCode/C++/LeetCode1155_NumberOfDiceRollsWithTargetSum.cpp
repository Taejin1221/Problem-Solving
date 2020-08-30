// LeetCode1155_NumberOfDiceRollsWithTargetSum.cpp
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
class Solution {
private:
	int DIVISOR = 1'000'000'007;

public:
	int numRollsToTarget( int dice, int face, int target ) {
		int dp[31][1001] = { 0, };

		for ( int i = 1; i <= target; i++ )
			dp[1][i] = ( i <= face ) ? 1 : -1;

		for ( int i = 2; i <= dice; i++ )
			for ( int j = 1; j <= target; j++ )
				for ( int k = 1; k < j; k++ )
					if ( dp[1][j - k + i - 2] != 0 )
						dp[i][j] = ( dp[i][j - 1] + dp[i - 1][j - 1] ) % DIVISOR;

		for ( int i = 1; i <= dice; i++ ) {
			for ( int j = 1; j <= target; j++ )
				cout << dp[i][j] << ' ';
			cout << endl;
		}

		return dp[dice][target];
	}
};