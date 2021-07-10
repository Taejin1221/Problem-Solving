// LeetCode0639.cpp
// https://leetcode.com/problems/decode-ways-ii/
#define MOD 1'000'000'007

class Solution {
	int validWays(char a) {
		if (a == '0')
			return 0;
		else if (a == '*')
			return 9;
		else
			return 1;
	}

	int validWays(char a, char b) {
		if (a == '1')
			return (b == '*') ? 9 : 1;
		else if (a == '2') {
			if (b == '*')
				return 6;
			if (b <= '6')
				return 1;
			else
				return 0;
		}
		else if (a == '*') {
			if (b == '*')
				return 15;
			else if ('0' <= b && b <= '6')
				return 2;
			else
				return 1;
		}
		else
			return 0;
	}
public:
	int numDecodings(string s) {
		int n = s.size();
		if (n == 1)
			return validWays(s[0]);

		vector<vector<long long>> dp(2, vector<long long> (n));

		dp[0][0] = validWays(s[0]);

		dp[0][1] = dp[0][0] * validWays(s[1]);
		dp[1][1] = validWays(s[0], s[1]);

		for (int i = 2; i < n; i++) {
			long long prev = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
			dp[0][i] = (prev * validWays(s[i])) % MOD;

			prev = (dp[0][i - 2] + dp[1][i - 2]) % MOD;
			dp[1][i] = (prev * validWays(s[i - 1], s[i]));
		}

		return (dp[0][n - 1] + dp[1][n - 1]) % MOD;
	}
};