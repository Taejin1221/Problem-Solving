// LeetCode0442_FindAllDuplicatesInAnArray.cpp
// https://leetcode.com/problems/find-all-duplicates-in-an-array/
// August Leetcoding Challenge Day 6
class Solution {
public:
	vector<int> findDuplicates( vector<int>& nums ) {
		map<int, int> m;
		for ( int n : nums ) {
			if ( m[n] )
				m[n]++;
			else
				m[n] = 1;
		}

		vector<int> ans;
		for ( auto i = m.begin(); i != m.end(); i++ )
			if ( i->second > 1 )
				ans.push_back( i->first );

		return ans;
	}
};