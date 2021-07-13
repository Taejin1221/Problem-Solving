// LeetCode0162.cpp
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int maxIdx = 0;
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] > nums[maxIdx])
				maxIdx = i;

		return maxIdx;
	}
};