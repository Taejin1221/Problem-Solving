/* Prob0112_PathSum.c */
typedef struct TreeNode TreeNode, * TreeNodePtr;

bool PathSum(TreeNodePtr root, int curr, int sum) {
	curr += root->val;

	if (root->left && root->right)
		return (PathSum(root->left, curr, sum) || PathSum(root->right, curr, sum));
	else if (root->left)
		return PathSum(root->left, curr, sum);
	else if (root->right)
		return PathSum(root->right, curr, sum);
	else {
		if (curr == sum) return true;
		else return false;
	}
}

bool hasPathSum(TreeNodePtr root, int sum) {
	if (root) return PathSum(root, 0, sum);
	else return false;
}