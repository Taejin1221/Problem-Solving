// LeetCode0532_K-diff-Pairs-in-an-Array.cpp
// https://leetcode.com/problems/k-diff-pairs-in-an-array/
// October LeetCoding Challenge Day 3
class Solution {
public:
	int findPairs( vector<int>& nums, int k ) {
		sort( nums.begin(), nums.end() );

		int prev = 10'000'001;
		int ptr1 = 0, ptr2 = 1, ans = 0;
		while ( ptr2 < nums.size() ) {
			int diff = nums[ptr2] - nums[ptr1];
			if ( diff < k )
				ptr2++;
			else if ( diff > k ) {
				prev = nums[ptr1];
				ptr1++;
				if ( ptr1 == ptr2 )
					ptr2++;
			} else {
				if ( prev != nums[ptr1] )
					ans++;
				prev = nums[ptr1];
				ptr1++;
				ptr2++;
			}
		}

		return ans;
	}
};