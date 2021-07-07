/* Prob0145_BinaryTreePostorderTraversal */
typedef int * intPtr;
typedef struct TreeNode TreeNode, * TreeNodePtr;

void Postorder(TreeNodePtr root, intPtr list, intPtr idx) {
	if (root) {
		Postorder(root->left, list, idx);
		Postorder(root->right, list, idx);
		list[(*idx)++] = root->val;
	}
}

intPtr postorderTraversal(TreeNodePtr root, intPtr returnSize) {
	intPtr list = malloc(sizeof(int) * 100);
	*returnSize = 0;

	Postorder(root, list, returnSize);

	return list;
}