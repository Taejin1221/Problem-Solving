// LeetCode0236_LowestCommonAncestorOfABinaryTree.cpp
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
class Solution {
	vector<TreeNode*> pPath, qPath;
	bool dfs(TreeNode* root, TreeNode* target, vector<TreeNode*>& targetPath) {
		if (root) {
			if (root == target) {
				targetPath.push_back(root);

				return true;
			} else {
				targetPath.push_back(root);
				if (dfs(root->left, target, targetPath) || dfs(root->right, target, targetPath))
					return true;

				targetPath.pop_back();
			}
		}

		return false;
	}

public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		dfs(root, p, pPath);
		dfs(root, q, qPath);

		int pIdx = pPath.size() - 1, qIdx = qPath.size() - 1;
		if (pIdx < qIdx) {
			while (pIdx != qIdx) {
				qIdx--;
				if (pPath[pIdx] == qPath[qIdx])
					return pPath[pIdx];
			}
		} else {
			while (pIdx != qIdx) {
				pIdx--;
				if (pPath[pIdx] == qPath[qIdx])
					return pPath[pIdx];
			}
		}

		while (pPath[pIdx] != qPath[qIdx])
			pIdx--, qIdx--;

		return pPath[pIdx];
	}
};