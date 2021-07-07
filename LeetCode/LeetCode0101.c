/* Prob0101_SymmetricTree.c */
typedef struct TreeNode TreeNode, * TreeNodePtr;

bool CompareSymmetric(TreeNodePtr rootLeft, TreeNodePtr rootRight) {
	// if rootLeft is null and rootRight is null, then subtree is symmetric
	if (!rootLeft && !rootRight)return true;
	// if rootLeft is null or rootRight is null, then subtree is non-symmetric
	else if (!rootLeft || !rootRight) return false;
	else {
		// if rootLeft->val is not same rootRight->val then, subtree is non-symmetric
		if (rootLeft->val != rootRight->val) return false;
		else
			return (CompareSymmetric(rootLeft->left, rootRight->right) &&
				CompareSymmetric(rootLeft->right, rootRight->left));
	}
}

bool isSymmetric(TreeNodePtr root){
	// if tree is empty, then that tree is symmetric
	if (!root) return true;
	return CompareSymmetric(root->left, root->right);
}