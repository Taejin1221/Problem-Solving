// LeetCode0783_MinimumDistanceBetweenBSTNodes.cpp
// https://leetcode.com/problems/minimum-distance-between-bst-nodes/
class Solution {
private:
	vector<int> nodes;
	void dfs( TreeNode* root ) {
		if ( root ) {
			dfs( root->left )
			nodes.push_back( root->val );
			dfs( root->right );
		}
	}

public:
	int minDiffInBST( TreeNode* root ) {
		dfs( root );

		int minVal = 1'000'000'000;
		for ( int i = 0; i < nodes.size() - 1; i++ )
			minVal = min( minVal, nodes[i + 1] - nodes[i] );

		return minVal;
	}
};