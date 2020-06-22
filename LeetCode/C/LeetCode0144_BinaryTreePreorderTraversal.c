/* Prob0144_BinaryTreePreorderTraversal.c */
typedef int * intPtr;
typedef struct TreeNode TreeNode, * TreeNodePtr;

void Preorder(TreeNodePtr root, intPtr list, intPtr idx) {
	if (root) {
		list[(*idx)++] = root->val;
		Preorder(root->left, list, idx);
		Preorder(root->right, list, idx);
	}
}

intPtr preorderTraversal(TreeNodePtr root, intPtr returnSize){
    intPtr list = malloc(sizeof(int) * 100);
    *returnSize = 0;

    Preorder(root, list, returnSize);

    return list;
}