/* Prob0105_ConstructBinaryTreeFromPreorderAndInorderTraversal.c */
#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
};

typedef int * intPtr;
typedef bool * boolPtr;
typedef struct TreeNode TreeNode, * TreeNodePtr;

TreeNodePtr CreateNode(int val) {
    TreeNodePtr newNode = (TreeNodePtr) malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;

    return newNode;
}

bool IsInRight(int inorder[], intPtr rootIdxPtr, bool check[], int target, int size) {
    for (int idx = *rootIdxPtr + 1; idx < size; idx++) {
        if (check[idx]) return false;
        if (inorder[idx] == target) {
            *rootIdxPtr = idx;
             return true;
         }
    }

    return false;
}

bool IsInLeft(int inorder[], intPtr rootIdxPtr, bool check[], int target) {
    for (int idx = *rootIdxPtr - 1; idx >= 0; idx--) {
        if (check[idx]) return false;
        if (inorder[idx] == target) {
            *rootIdxPtr = idx;
             return true;
         }
    }

    return false;
}

TreeNodePtr buildSubTree(TreeNodePtr root, int inorder[], int inorderSize, int preorder[], int preorderSize, int rootIdx, intPtr preIdxPtr, bool check[]) {
    if (*preIdxPtr > preorderSize) { root = CreateNode(inorder[rootIdx]); return root; };

    root = CreateNode(inorder[rootIdx]);
    check[rootIdx] = true;
    int nextRootIdx = rootIdx;

    if (IsInLeft(inorder, &nextRootIdx, check, preorder[*preIdxPtr])) {
        (*preIdxPtr)++;
        root->left = buildSubTree(root->left, inorder, inorderSize, preorder, preorderSize, nextRootIdx, preIdxPtr, check);
    }
    nextRootIdx = rootIdx;
    if (*preIdxPtr > preorderSize) return root;
    if (IsInRight(inorder, &nextRootIdx, check, preorder[*preIdxPtr], inorderSize)) {
        (*preIdxPtr)++;
        root->right = buildSubTree(root->right, inorder, inorderSize, preorder, preorderSize, nextRootIdx, preIdxPtr, check);
    }

    return root;
}

TreeNodePtr buildTree(intPtr inorder, int inorderSize, intPtr preorder, int preorderSize) {
    // if tree is empty
    if (! inorderSize) return NULL;

    boolPtr check = calloc(inorderSize, sizeof(bool));

    int preIdx = 0, rootIdx = 0;
    while (inorder[rootIdx] != preorder[preIdx]) rootIdx++;
    preIdx++;
    TreeNodePtr root = NULL;
    root = buildSubTree(root, inorder, inorderSize, preorder, preorderSize, rootIdx, &preIdx, check);

    return root;
}
