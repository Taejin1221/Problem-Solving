// LeetCode0350.cpp
// https://leetcode.com/problems/intersection-of-two-arrays-ii/
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ans;
		sort(nums2.begin(), nums2.end());

		bool isSelcted[1'000] = { false, };

		int n = nums2.size();
		for (int i = 0; i < nums1.size(); i++) {
			int idx = lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
			while (idx < n && isSelcted[idx] && nums2[idx] == nums1[i])
				idx++;

			if (idx < n && !isSelcted[idx] && nums2[idx] == nums1[i]) {
				isSelcted[idx] = true;
				ans.push_back(nums1[i]);
			}
		}

		return ans;
	}
};