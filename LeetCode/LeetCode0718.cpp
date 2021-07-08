// LeetCode0718.cpp
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
class Solution {
public:
	int findLength(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size(), m = nums2.size();

		int ans = 0;
		vector<vector<int>> dp(n, vector<int> (m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0 || j == 0)
					dp[i][j] = (nums1[i] == nums2[j]);
				else
					if (nums1[i] == nums2[j])
						dp[i][j] = dp[i - 1][j - 1] + 1;

				ans = max(ans, dp[i][j]);
			}
		}

		return ans;
	}
};