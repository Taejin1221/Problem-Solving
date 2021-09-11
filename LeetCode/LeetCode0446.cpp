// LeetCode0446.cpp
// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
typedef long long ll;

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& nums) {
		int n = nums.size();

		int ans = 0;
		vector<map<ll, int>> dp(n);
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				ll diff = (ll)nums[i] - nums[j];

				auto findIter = dp[j].find(diff);
				if (findIter == dp[j].end())
					dp[i][diff] += 1;
				else {
					dp[i][diff] += findIter->second + 1;
					ans += findIter->second;
				}
			}
		}

		return ans;
	}
};