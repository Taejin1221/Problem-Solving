/* Prob104.c */
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

typedef struct TreeNode TreeNode, * TreeNodePtr;

int maxDepth(TreeNodePtr root) {
	// if root is not null
	if (root)
		return 1 + MAX(maxDepth(root->left), maxDepth(root->right));
	else
		return 0;
}