// LeetCode0018.cpp
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int n = nums.size();
		vector<vector<int>> ans;
		if (n < 4)
			return ans;

		sort(nums.begin(), nums.end());

		set<vector<int>> sums;
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				for (int k = j + 1; k < n; k++) {
					int currTarget = target - nums[i] - nums[j] - nums[k];
					int idx = lower_bound(nums.begin() + k + 1, nums.end(), currTarget) - nums.begin();
					if (idx < n && nums[idx] == currTarget)
						sums.insert(vector<int> {nums[i], nums[j], nums[k], nums[idx]});
				}
			}
		}

		for (auto iter = sums.begin(); iter != sums.end(); ++iter)
			ans.push_back(*iter);

		return ans;
	}
};