// Prob0104_MaximumDepthOfBinaryTree.cpp
typedef struct TreeNode TreeNode, * TreeNodePtr;

typedef struct QueueValue {
	TreeNodePtr root;
	int height;
} QueueValue;

class Solution {
public:
	int maxDepth(TreeNodePtr root) {
		if (! root)
			return 0;

		queue<QueueValue> que;
		int depth = 0;

		que.push( { root, 1 } );
		while (! que.empty()) {
			QueueValue curr =  que.front();	que.pop();

			if (curr.root->left)
				que.push( { curr.root->left, curr.height + 1 } );
			if (curr.root->right)
				que.push( { curr.root->right, curr.height + 1 } );

			if (curr.height > depth) depth = curr.height;
		}

		return depth;
	}

	int maxDepth(TreeNodePtr root) {
		if (! root) return 0;

		queue<TreeNodePtr> que;
		int height = 0;

		que.push(root);
		while (! que.empty()) {
			height++;
			int size = que.size();

			for (int i = 0; i < size; i++) {
				TreeNodePtr temp = que.front(); que.pop();
				if (temp->left) que.push(temp->left);
				if (temp->right) que.push(temp->right);
			}
		}

		return height;
	}


	int max(int a, int b) {
		return (a > b ? a : b);
	}
	
	int maxDepth(TreeNodePtr root) {
		if (root)
			return max(maxDepth(root->left), maxDepth(root->right)) + 1;
		else
			return 0;
	}
};