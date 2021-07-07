// LeetCode1695_MaximumErasureValue.cpp
// https://leetcode.com/problems/maximum-erasure-value/
// LeetCode Weekly Contest 220
class Solution {
public:
	int maximumUniqueSubarray( vector<int>& nums ) {
		bool table[10'001] = { false, };
		int sum = 0, maxVal = 0, left = 0, right;
		for ( right = 0; right < nums.size(); right++ ) {
			if ( table[nums[right]] ) {
				while ( nums[left] != nums[right] ) {
					table[nums[left]] = false;
					sum -= nums[left];
					left++;
				}

				table[nums[left]] = false;
				sum -= nums[left];
				left++;
			}

			table[nums[right]] = true;
			sum += nums[right];

			maxVal = max( maxVal, sum );
		}	

		return maxVal;
	}
};
