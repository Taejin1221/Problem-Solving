/* Prob0094_BinaryTreeInorderTraversal.c */
typedef int * intPtr;
typedef struct TreeNode TreeNode, * TreeNodePtr;

void Inorder(TreeNodePtr root, intPtr list, intPtr idx) {
	if (root) {
		Inorder(root->left, list, idx);
		list[(*idx)++] = root->val;
		Inorder(root->right, list, idx);
	}
}

intPtr inorderTraversal(TreeNodePtr root, intPtr returnSize) {
	intPtr list = malloc(sizeof(int) * 100);
	*returnSize = 0;

	Inorder(root, list, returnSize);

	return list;
}