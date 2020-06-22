/* Prob109.c */
typedef struct ListNode ListNode, * ListNodePtr;
typedef struct TreeNode TreeNode, * TreeNodePtr;

int ListLen(ListNodePtr head) {
	int len = 0;
	for (ListNodePtr curr = head; curr; curr = curr->next)
		len++;

	return len;
}

ListNodePtr AcessList(ListNodePtr head, int idx) {
	ListNodePtr target = head;
	for (int i = 0; i < idx; i++)
		target = target->next;

	return target;
}

TreeNodePtr InsertTreeNode(TreeNodePtr root, int data) {
	TreeNodePtr newNode = malloc(sizeof(TreeNode));
	newNode->val = data;
	newNode->left = newNode->right = NULL;

	if (! root) root = newNode;
	else {
		TreeNodePtr curr = root;
		while (1) {
			if (newNode->val < curr->val) {
				if (! curr->left) {
					curr->left = newNode;
					break;
				}
				else
					curr = curr->left;
			}
			else {
				if (! curr ->right) {
					curr->right = newNode;
					break;
				}
				else
					curr = curr->right;
			}
		}
	}

	return root;
}

TreeNodePtr CreateBST(TreeNodePtr root, ListNodePtr head, int left, int right) {
	if (left <= right) {
		int mid = (left + right) / 2;
		root = InsertTreeNode(root, AcessList(head, mid)->val);
		root = CreateBST(root, head, left, mid - 1);
		root = CreateBST(root, head, mid + 1, right);
	}

	return root;
}

TreeNodePtr sortedListToBST(ListNodePtr head) {
	TreeNodePtr root = NULL;
	int len = ListLen(head);

	root = CreateBST(root, head, 0, len - 1);

	return root;
}