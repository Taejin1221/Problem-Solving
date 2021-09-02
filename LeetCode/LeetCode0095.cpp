// LeetCode0095.cpp
class Solution {
	void increment(TreeNode* root, int val) {
		if (root) {
			root->val += val;
			increment(root->left, val);
			increment(root->right, val);
		}
	}

	TreeNode* copy(TreeNode* root) {
		if (root) {
			TreeNode* copiedRoot = new TreeNode(root->val);
			copiedRoot->left = copy(root->left);
			copiedRoot->right = copy(root->right);

			return copiedRoot;
		} else
			return nullptr;
	}

public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 1)
			return vector<TreeNode*> (1, new TreeNode(1));

		vector<TreeNode*> ans, small = generateTrees(n - 1), big = generateTrees(n - 1);
		for (int i = 0; i < small.size(); i++) {
			increment(big[i], 1);
			TreeNode* root1 = new TreeNode(1);
			root1->right = big[i];

			TreeNode* root2 = new TreeNode(n);
			root2->left = small[i];

			ans.push_back(root1);
			ans.push_back(root2);
		}

		for (int i = 2; i < n; i++) {
			big = generateTrees(n - i);
			small = generateTrees(i - 1);
			for (int bIdx = 0; bIdx < big.size(); bIdx++) {
				increment(big[bIdx], i);
				for (int sIdx = 0; sIdx < small.size(); sIdx++) {
					TreeNode* currRoot = new TreeNode(i);
					currRoot->left = copy(small[sIdx]);
					currRoot->right = copy(big[bIdx]);

					ans.push_back(currRoot);
				}
			}

		}

		return ans;
	}
};