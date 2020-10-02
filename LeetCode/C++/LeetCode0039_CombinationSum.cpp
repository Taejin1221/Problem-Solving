// LeetCode0039_CombinationSum.cpp
// https://leetcode.com/problems/combination-sum/
// October LeetCoding Challenge Day 2
class Solution {
private:
	void dfs( vector<vector<int>>& ans, vector<int>& candidates, vector<int>& curr, int idx, int currVal ) {
		if ( currVal == 0 )
			ans.push_back( curr );
		else if ( currVal < 0 )
			return;
		else {
			for ( int i = idx; i < candidates.size(); i++ ) {
				curr.push_back( candidates[i] );
				dfs( ans, candidates, curr, i, currVal - candidates[i] );
				curr.pop_back( );
			}
		}
	}

public:
	vector<vector<int>> combinationSum( vector<int>& candidates, int target ) {
		vector<int> curr;
		vector<vector<int>> ans;

		dfs( ans, candidates, curr, 0, target );

		return ans;
	}
};