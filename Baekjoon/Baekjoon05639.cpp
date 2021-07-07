// Baekjoon05639_BinarySearchTree.cpp
// https://www.acmicpc.net/problem/5639
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left, *right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
};

typedef TreeNode * TreeNodePtr;

TreeNodePtr InsertNode( TreeNodePtr root, int val );
void PostOrder( TreeNodePtr root );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int val;
	TreeNodePtr root = nullptr;
	while ( cin >> val )
		root = InsertNode( root, val );

	PostOrder( root );

	return 0;
}

TreeNodePtr InsertNode( TreeNodePtr root, int val ) {
	if ( !root )
		return (new TreeNode( val ));
	else {
		if ( root->val > val )
			root->left = InsertNode( root->left, val );
		else
			root->right = InsertNode( root->right, val );
		return root;
	}
}

void PostOrder( TreeNodePtr root ) {
	if ( root ) {
		PostOrder( root->left );
		PostOrder( root->right );
		cout << root->val << '\n';
	}
}