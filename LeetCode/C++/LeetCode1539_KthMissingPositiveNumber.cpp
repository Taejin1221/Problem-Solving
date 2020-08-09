// LeetCode1539_KthMissingPositiveNumber.cpp
// https://leetcode.com/problems/kth-missing-positive-number/
// LeetCode Biweekly Contest 32 A
class Solution {
public:
	int findKthPositive( vector<int>& arr, int k ) {
		bool table[2001] = { false, };

		for ( int a : arr )
			table[a] = true;

		int idx = 1;
		while ( true ) {
			if ( !table[idx] )
				k--;

			if ( k == 0 )
				return idx;
			idx++;
		}
	}
}