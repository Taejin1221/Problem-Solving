/* Prob0106_ConstructBinaryTreeFromInorderAndPostorderTraversal.c */
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

TreeNodePtr buildSubTree(TreeNodePtr root, int inorder[], int inorderSize, int postorder[], int rootIdx, intPtr postIdxPtr, bool check[]) {
    root = CreateNode(inorder[rootIdx]);
    
    if (*postIdxPtr < 0) return root;

    check[rootIdx] = true;
    int nextRootIdx = rootIdx;

    if (IsInRight(inorder, &nextRootIdx, check, postorder[*postIdxPtr], inorderSize)) {
        (*postIdxPtr)--;
        root->right = buildSubTree(root->right, inorder, inorderSize, postorder, nextRootIdx, postIdxPtr, check);
    }
    nextRootIdx = rootIdx;
    if (*postIdxPtr < 0) return root;
    if (IsInLeft(inorder, &nextRootIdx, check, postorder[*postIdxPtr])) {
        (*postIdxPtr)--;
        root->left = buildSubTree(root->left, inorder, inorderSize, postorder, nextRootIdx, postIdxPtr, check);
    }

    return root;
}

TreeNodePtr buildTree(intPtr inorder, int inorderSize, intPtr postorder, int postorderSize) {
    // if tree is empty
    if (! inorderSize) return NULL;

    boolPtr check = calloc(inorderSize, sizeof(bool));

    int postIdx = postorderSize - 1, rootIdx = 0;
    while (inorder[rootIdx] != postorder[postIdx]) rootIdx++;
    postIdx--;
    TreeNodePtr root = NULL;
    root = buildSubTree(root, inorder, inorderSize, postorder, rootIdx, &postIdx, check);

    return root;
}
