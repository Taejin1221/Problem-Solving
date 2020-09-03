// LeetCode1470_ShuffleTheArray.cpp
// https://leetcode.com/problems/shuffle-the-array/
class Solution {
public:
	vector<int> shuffle( vector<int>& nums, int n ) {
		vector<int> ans( nums.size() );

		int doubleN = n * 2;

		int idx = 0, i = 0, j = n;
		while ( idx < doubleN ) {
			ans[idx++] = nums[i++];
			ans[idx++] = nums[j++];
		}

		return ans;
	}
};