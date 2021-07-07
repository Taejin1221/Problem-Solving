// LeetCode0437_PathSumIII.cpp
// https://leetcode.com/problems/path-sum-iii/
// August Leetcoding Challenge Day 8
typedef long long ll;
typedef TreeNode * TreeNodePtr;

class Solution {
private:
	void dfs( TreeNodePtr root, ll sum, bool in, int& time ) {
		if ( !root )
			return;

		if ( sum - root->val == 0 )
			time++;

		dfs( root->left, sum - root->val, true, time );
		dfs( root->right, sum - root->val, true, time );

		if ( !in ) {
			dfs( root->left, sum, false, time );
			dfs( root->right, sum, false,  time );	
		}
	}

public:
	int pathSum( TreeNodePtr root, int sum ) {
		int time = 0;

		dfs( root, (ll)sum, false, time );

		return time;
	}
};