// LeetCode0034_FindFirst-and-LastPosition-of-Element-in-SortedArray.cpp
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
	vector<int> searchRange( vector<int>& nums, int target ) {
		vector<int> ans { -1, -1 };
		if ( nums.size() > 0 ) {
			int start = 0, end = nums.size() - 1;
			while ( start <= end ) {
				int mid = ( start + end ) / 2;
				if ( nums[mid] < target ) {
					start = mid + 1;
				} else {
					end = mid - 1;
				}
			}
	
			if ( end + 1 < nums.size() && nums[end + 1] == target )
				ans[0] = end + 1;
	
			start = 0, end = nums.size() - 1;
			while ( start <= end ) {
				int mid = ( start + end ) / 2;
				if ( nums[mid] <= target )
					start = mid + 1;
				else
					end = mid - 1;
			}
	
			if ( 0 < start && nums[start - 1] == target  )
				ans[1] = start - 1;
		}

		return ans;
	}
};