class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushAllRight(TreeNode* node) {
        while (node != NULL) {
            st.push(node);
            node = node->right;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAllRight(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if (node->left != NULL) {
            pushAllRight(node->left);
        }

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};
