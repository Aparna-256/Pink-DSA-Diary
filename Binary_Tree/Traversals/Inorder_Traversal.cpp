/**
 * Definition for a binary tree node.
 */

RECURSIVE APPROACH

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

----------------------------------------------------------------------

    
ITERATIVE APPROACH

    
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;

    while (root || !st.empty()) {
        // go to leftmost node
        while (root) {
            st.push(root);
            root = root->left;
        }

        root = st.top();
        st.pop();

        res.push_back(root->val);

        root = root->right;
    }

    return res;
}
