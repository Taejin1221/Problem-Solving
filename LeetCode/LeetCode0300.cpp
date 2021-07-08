// LeetCode0300.cpp
// https://leetcode.com/problems/longest-increasing-subsequence/
class Solution {
public:
	// O(n^2) Solution
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();

		int ans = 1;
		vector<int> dp(n, 1);
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j < n; j++) {
				if (nums[i] < nums[j])
					dp[i] = max(dp[i], dp[j] + 1);
			}

			ans = max(ans, dp[i]);
		}

		return ans;
	}

	// O(n log n) Solution
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();

		vector<int> list(1, nums[0]);
		for (int i = 1; i < n; i++) {
			int lower = lower_bound(list.begin(), list.end(), nums[i]) - list.begin();
			if (lower == list.size())
				list.push_back(nums[i]);
			else
				list[lower] = nums[i];
		}

		return list.size();
	}
};