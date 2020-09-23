// LeetCode0053_MaximumSubarray.cpp
// https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
	int maxSubArray( vector<int>& nums ) {
		int maxVal = nums[0], sum = nums[0];
		for ( int i = 1; i < nums.size(); i++ ) {
			sum = max( nums[i], sum + nums[i] );
			maxVal = max( maxVal, sum );
		}

		return maxVal;
	}
};