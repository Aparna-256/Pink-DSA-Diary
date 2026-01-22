int kthLargest(TreeNode* root, int k) {
    stack<TreeNode*> st;

    while(root != NULL || !st.empty()){
        while(root != NULL){
            st.push(root);
            root = root->right;
        }

        root = st.top();
        st.pop();
        k--;

        if(k == 0){
            return root->val;
        }

        root = root->left;
    }
    return -1;
}
