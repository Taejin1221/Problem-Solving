// LeetCode0322_CoinChange.cpp
// https://leetcode.com/problems/coin-change/
class Solution {
private:
	const int INF = 1'000'000'000;

public:
	int coinChange( vector<int>& coins, int amount ) {
		vector<int> dp ( amount + 1, INF );

		dp[0] = 0;
		for ( int i = 1; i <= amount; i++ )
			for ( int j = 0; j < coins.size(); j++ )
				if ( i >= coins[j] )
					dp[i] = min( dp[i], dp[i - coins[j]] + 1 );

		return (dp[amount] >= INF) ? -1 : dp[amount];
	}
};