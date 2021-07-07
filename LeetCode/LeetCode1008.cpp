// LeetCode1008_ConstructBinarySearchTreeFromPreoderTraversal.cpp
typedef TreeNode * TreeNodePtr;

class Solution {
public:
	TreeNodePtr helper(vector<int>& preorder, int start, int end) {
		if (start > end)
			return NULL;
		else {
			TreeNodePtr root = new TreeNode(preorder[start]);

			int leftStart = start + 1, rightStart = start + 1;
			while ((rightStart <= end) && (preorder[rightStart] < preorder[start]))
				rightStart++;

			root->left = helper(preorder, leftStart, rightStart - 1);
			root->right = helper(preorder, rightStart, end);

			return root;
		}
	}

	TreeNode* bstFromPreorder(vector<int>& preorder) {
		return helper(preorder, 0, preorder.size() - 1);
	}
};