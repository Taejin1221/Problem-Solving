// LeetCode0100_SameTree.cpp
// https://leetcode.com/problems/same-tree/
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if ( p && q ) {
			if ( p->val != q->val )
				return false;
			else
				return (isSameTree( p->left, q->left ) && isSameTree( p->right, q->right ));
		} else if ( !p && !q )
			return true;
		else
			return false;
	}
};