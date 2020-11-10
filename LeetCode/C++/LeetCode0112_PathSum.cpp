// LeetCode0112_PathSum.cpp
// https://leetcode.com/problems/path-sum/
class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if ( !root )
			return false;
		if ( !root->left && !root->right ) {
			if ( sum - root->val )
				return false;
			else
				return true;
		} else {
			bool result = false;
			if ( root->left )
				result = hasPathSum( root->left, sum - root->val );
			if ( root->right )
				result = result || hasPathSum( root->right, sum - root->val );

			return result;
		}
	}
};