// LeetCode0235.cpp
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) {
            TreeNode* temp = p;
            p = q;
            q = temp;
        }

        if (p->val <= root->val && root->val <= q->val)
            return root;
        else if (q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }
};