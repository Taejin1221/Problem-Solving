// LeetCode0078_Subsets.cpp
// https://leetcode.com/problems/subsets/
class Solution {
private:
	void backtracking( vector<vector<int>>& ans, vector<int>& nums, vector<int> curr, int idx ) {
		ans.push_back( curr );
		if ( nums.size() == idx )
			return;
		else {
			for ( int i = idx; i < nums.size(); i++ ) {
				curr.push_back( nums[i] );
				backtracking( ans, nums, curr, i + 1 );
				curr.pop_back( );
			}
		}
	}

public:
	vector<vector<int>> subsets( vector<int>& nums ) {
		vector<vector<int>> ans;
		backtracking( ans, nums, vector<int> (), 0 );

		return ans;
	}
};