// LeetCode1220_CountVowelsPermutation.cpp
// https://leetcode.com/problems/count-vowels-permutation/
#define MOD 1'000'000'007

class Solution {
public:
	int countVowelPermutation(int n) {
		long long dp[5][200'001] = { 0, };
		for (int i = 0; i < 5; i++)
			dp[i][1] = 1ll;

		for (int i = 2; i <= n; i++) {
			dp[0][i] = (dp[0][i] + dp[1][i - 1]) % MOD;
			dp[1][i] = (dp[1][i] + dp[0][i - 1] + dp[2][i - 1]) % MOD;
			dp[2][i] = (dp[2][i] + dp[0][i - 1] + dp[1][i - 1] + dp[3][i - 1] + dp[4][i - 1]) % MOD;
			dp[3][i] = (dp[3][i] + dp[2][i - 1] + dp[4][i - 1]) % MOD;
			dp[4][i] = (dp[4][i] + dp[0][i - 1]) % MOD;
		}

		int ans = 0;
		for (int i = 0; i < 5; i++)
			ans = (ans + dp[i][n]) % MOD;

		return ans;
	}
};