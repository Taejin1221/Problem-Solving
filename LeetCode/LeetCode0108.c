/* Prob0108_ConvertSortedArrayToBinarySearchTree.c */
typedef int * intPtr;
typedef struct TreeNode TreeNode, * TreeNodePtr;

/*TreeNodePtr InsertTreeNode(TreeNodePtr root, int data) {
	TreeNodePtr newNode = malloc(sizeof(TreeNode));
	newNode->val = data;
	newNode->left = newNode->right = NULL;

	// if root is NULL
	if (! root) root = newNode;
	else {
		TreeNodePtr curr = root;
		while (1) {
			if (curr->val > data) {
				if (! curr->left) {
					curr->left = newNode;
					break;
				} else {
					curr = curr->left;
				}
			} else {
				if (! curr->right) {
					curr->right = newNode;
					break;
				} else {
					curr = curr->right;
				}
			}
		}
	}

	return root;
}*/

TreeNodePtr InsertTreeNode(TreeNodePtr root, int data) {
	TreeNodePtr newNode = malloc(sizeof(TreeNode));
	newNode->val = data;
	newNode->left = newNode->right = NULL;

	if (! root) root = newNode;
	else {
		if (root->val > data)
			root->left = InsertTreeNode(root->left, data);
		else
			root->right = InsertTreeNode(root->right, data);
	}

	return root;
}

TreeNodePtr CreateBST(TreeNodePtr root, intPtr nums, int left, int right) {
	if (left <= right) {
		int mid = (left + right) / 2;
		root = InsertTreeNode(root, nums[mid]);
		root = CreateBST(root, nums, left, mid - 1);
		root = CreateBST(root, nums, mid + 1, right);
	}

	return root;
}

TreeNodePtr sortedArrayToBST(intPtr nums, int numsSize){
	TreeNodePtr root = NULL;

	root = CreateBST(root, nums, 0, numsSize - 1);

	return root;
}