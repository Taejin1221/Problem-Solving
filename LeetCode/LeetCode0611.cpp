// LeetCode0611.cpp
// https://leetcode.com/problems/valid-triangle-number/
typedef long long ll;

class Solution {
public:
	int triangleNumber(vector<int>& nums) {
		if (nums.size() < 3)
			return 0;

		int ans = 0;
		sort(nums.begin(), nums.end());

		int n = nums.size();
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
                if (nums[i] == 0 || nums[j] == 0)
                    continue;

				ll findNum = (ll)nums[i] + nums[j];
				int idx = lower_bound(nums.begin(), nums.end(), nums[i] + nums[j]) - nums.begin();
				if (idx == n || findNum <= nums[idx])
					ans += (idx - 1) - j;
				else
					ans += idx - j;
			}
		}

		return ans;
	}
};