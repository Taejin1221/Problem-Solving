// LeetCode0111_MinimumDepthOfBinaryTree.cpp
// https://leetcode.com/problems/minimum-depth-of-binary-tree/
class Solution {
public:
	int minDepth( TreeNode* root ) {
		if ( root == NULL )
			return 0;

		int ans = 0;

		queue<pair<TreeNode*, int>> q;
		q.push( make_pair( root, 1 ) );

		bool run = true;
		while ( run && !q.empty() ) {
			pair<TreeNode*, int> node = q.front();
			q.pop();

			if ( node.first->left == NULL && node.first->right == NULL ) {
				ans = node.second;
				run = false;
			} else {
				if ( node.first->left != NULL )
					q.push( make_pair( node.first->left, node.second + 1 ) );

				if ( node.first->right != NULL )
					q.push( make_pair( node.first->right, node.second + 1 ) );
			}
		}

		return ans;
	}
};