// LeetCode0938_RangeSumOfBST.cpp
// https://leetcode.com/problems/range-sum-of-bst/
class Solution {
public:
	int rangeSumBST( TreeNode* root, int L, int R ) {
		if ( !root )
			return 0;
		else {
			int ans = 0;
			if ( L <= root->val )
				ans += rangeSumBST( root->left, L, R );
			if ( root->val <= R )
				ans += rangeSumBST( root->right, L, R );
			if ( L <= root->val && root->val <= R )
				ans += root->val;

			return ans;
		}
	}
};