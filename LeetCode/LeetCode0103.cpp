// LeetCode0103_BinaryTreeZigzagLevelOrderTraversal.cpp
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
typedef TreeNode* TreeNodePtr;

struct Node {
	TreeNodePtr node;
	int level;
	Node( TreeNodePtr n, int l ): node(n), level(l) {}
};

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder( TreeNodePtr root ) {
		if ( root == NULL )
			return {};

		vector<vector<int>> ans;
		vector<int> temp;

		queue<Node> q; q.push( Node( root, 1 ) );
		while ( !q.empty() ) {
			Node curr = q.front(); q.pop();
			temp.push_back( curr.node->val );

			if ( curr.node->left )
				q.push( Node( curr.node->left, curr.level + 1 ) );
			if ( curr.node->right )
				q.push( Node( curr.node->right, curr.level + 1 ) );

			if ( !q.empty() && curr.level != q.front().level ) {
				ans.push_back( temp );
				temp.clear();
			}
		}
		ans.push_back( temp );

		for ( int i = 1; i < ans.size(); i += 2 )
			reverse( ans[i].begin(), ans[i].end() );

		return ans;
	}
};