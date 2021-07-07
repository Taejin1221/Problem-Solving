// LeetCode0113_PathSumII.cpp
// https://leetcode.com/problems/path-sum-ii/
typedef TreeNode * TreeNodePtr;

class Solution {
public:
	void dfs( TreeNodePtr root, int curr, vector<int>& temp, vector<vector<int>>& ans ) {
		curr -= root->val;

		temp.push_back( root->val );
		if ( (!root->left && !root->right) && ( !curr ) )
			ans.push_back( temp );
		else {
			if ( root->left )
				dfs( root->left, curr, temp, ans );
			if ( root->right )
				dfs( root->right, curr, temp, ans );
		}
		temp.pop_back();
	}

	vector<vector<int>> pathSum( TreeNodePtr root, int sum ) {
		vector<int> temp;
		vector<vector<int>> ans;

		if ( root )
			dfs( root, sum, temp, ans );

		return ans;
	}
};