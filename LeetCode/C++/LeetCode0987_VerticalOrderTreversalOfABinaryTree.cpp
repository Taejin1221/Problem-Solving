// LeetCode0987_VerticalOrderTreversalOfABinaryTree.cpp
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// August Leetcoding Challenge Day 7
// Solution 1 ( 1772ms )
typedef TreeNode * TreeNodePtr;

struct Node {
	TreeNodePtr root;
	int x, y;
	Node( TreeNodePtr r, int x, int y ): root(r), x(x), y(y) {}
};

class Solution {
public:
	vector<vector<int>> verticalTraversal( TreeNode* root ) {
		vector<int> nodes[1000][2000];

		queue<Node> q;
		q.push( Node( root, 1000, 999 ) );
		while ( !q.empty() ) {
			Node curr = q.front(); q.pop();

			nodes[curr.y][curr.x].push_back( curr.root->val );
			if ( curr.root->left )
				q.push( Node( curr.root->left, curr.x - 1, curr.y - 1 ) );

			if ( curr.root->right )
				q.push( Node( curr.root->right, curr.x + 1, curr.y - 1 ) );
		}

		vector<vector<int>> ans;
		for ( int i = 0; i < 2000; i++ ) {
			vector<int> currVec;
			for ( int j = 999; j >= 0; j-- ) {
				if ( nodes[j][i].size() ) {
					sort( nodes[j][i].begin(), nodes[j][i].end() );
					currVec.insert( currVec.end(), nodes[j][i].begin(), nodes[j][i].end() );
				}
			}
			if ( currVec.size() )
				ans.push_back( currVec );
		}

		return ans;
	}
};

// Solution 2 ( 4ms )
typedef TreeNode * TreeNodePtr;
typedef pair<int, int> pii;

struct Node {
	TreeNodePtr root;
	int level, x;
	Node( TreeNodePtr r, int l, int x ): root(r), level(l), x(x) {}
};

bool compare( pii a, pii b ) {
	if ( a.second != b.second )
		return a.second < b.second;
	else
		return a.first < b.first;
}

class Solution {
public:
	vector<vector<int>> verticalTraversal( TreeNode* root ) {
		vector<pii> table[2000];

		queue<Node> q;
		q.push( Node( root, 0, 1000 ) );
		while ( !q.empty() ) {
			Node curr = q.front(); q.pop();

			table[curr.x].push_back( { curr.root->val, curr.level } );
			if ( curr.root->left )
				q.push( Node( curr.root->left, curr.level + 1, curr.x - 1 ) );
			if ( curr.root->right )
				q.push( Node( curr.root->right, curr.level + 1, curr.x + 1 ) );
		}

		vector<vector<int>> ans;
		for ( int i = 0; i < 2000; i++ ) {
			if ( table[i].size() ) {
				sort( table[i].begin(), table[i].end(), compare );
				vector<int> temp;
				for ( pii& t : table[i] )
					temp.push_back( t.first);
				ans.push_back( temp );
			}
		}

		return ans;
	}
};