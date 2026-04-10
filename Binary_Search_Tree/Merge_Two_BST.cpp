BRUTE FORCE

SPACE(M+N)
TIME (M+N)

// Helper to get inorder sequence
void inorder(Node* root, vector<int>& v) {
    if (root == NULL) return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

// Helper to build a balanced BST from sorted array
Node* buildBST(int start, int end, vector<int>& v) {
    if (start > end) return NULL;

    int mid = start + (end - start) / 2;
    Node* root = new Node(v[mid]);

    root->left = buildBST(start, mid - 1, v);
    root->right = buildBST(mid + 1, end, v);

    return root;
}

// Main function to merge two BSTs
Node* mergeTwoBSTs(Node* root1, Node* root2) {
    vector<int> bst1, bst2, merged;

    inorder(root1, bst1);
    inorder(root2, bst2);

    // Merge two sorted arrays
    int i = 0, j = 0;

    while (i < bst1.size() && j < bst2.size()) {
        if (bst1[i] < bst2[j]) merged.push_back(bst1[i++]);
        else merged.push_back(bst2[j++]);
    }

    while (i < bst1.size()) merged.push_back(bst1[i++]);
    while (j < bst2.size()) merged.push_back(bst2[j++]);

    return buildBST(0, merged.size() - 1, merged);
}
