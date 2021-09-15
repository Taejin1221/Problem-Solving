// LeetCode0978.cpp
// https://leetcode.com/problems/longest-turbulent-subarray/
class Solution {
public:
	int maxTurbulenceSize(vector<int>& arr) {
		int n = arr.size();

		// [0] -> k % 2 == 1일 때 증가, [1] -> k % 2 == 1 일 때 감소
		vector<vector<int>> dp(2, vector<int>(n));
		dp[0][0] = dp[1][0] = 1;

		int ans = 1;
		for (int i = 1; i < n; i++) {
			if (i % 2) {
				if (arr[i - 1] < arr[i]) {
					dp[0][i] = dp[0][i - 1] + 1;
					dp[1][i] = 1;
				} else if (arr[i - 1] == arr[i]) {
					dp[0][i] = 1;
					dp[1][i] = 1;
				} else {
					dp[0][i] = 1;
					dp[1][i] = dp[1][i - 1] + 1;
				}
			} else {
				if (arr[i - 1] > arr[i]) {
					dp[0][i] = dp[0][i - 1] + 1;
					dp[1][i] = 1;
				} else if (arr[i - 1] == arr[i]) {
					dp[0][i] = 1;
					dp[1][i] = 1;
				} else {
					dp[0][i] = 1;
					dp[1][i] = dp[1][i - 1] + 1;
				}
			}

			ans = max(ans, max(dp[0][i], dp[1][i]));
		}

		return ans;
	}
};