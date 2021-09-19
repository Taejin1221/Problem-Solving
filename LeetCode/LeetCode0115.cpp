// LeetCode0115.cpp
// https://leetcode.com/problems/distinct-subsequences/
class Solution {
public:
	int numDistinct(string s, string t) {
		int n = s.size(), m = t.size();
		long long dp[1'000][1'000] = { 0, };

		dp[n - 1][m - 1] = s[n - 1] == t[m - 1];
		for (int i = n - 2; i >= 0; i--) {
			dp[i][m - 1] = dp[i + 1][m - 1];
			if (s[i] == t[m - 1])
				dp[i][m - 1]++;
		}

		for (int i = m - 2; i >= 0; i--) {
			for (int j = n - 2; j >= i; j--) {
				dp[j][i] = dp[j + 1][i];
				if (s[j] == t[i])
					dp[j][i] += dp[j + 1][i + 1];
			}
		}

		return dp[0][0];
	}
};