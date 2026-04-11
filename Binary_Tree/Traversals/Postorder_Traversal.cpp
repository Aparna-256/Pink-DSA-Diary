RECUSSION APPROACH

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void postorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};

-------------------------------------------------------------------------------

2-STACK APPROACH

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;

    stack<TreeNode*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        TreeNode* node = st1.top();
        st1.pop();
        st2.push(node);

        if (node->left) st1.push(node->left);
        if (node->right) st1.push(node->right);
    }

    while (!st2.empty()) {
        res.push_back(st2.top()->val);
        st2.pop();
    }

    return res;
}

---------------------------------------------------------------------------------------

1-STACK APPROACH

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* lastVisited = NULL;

    while (root || !st.empty()) {
        if (root) {
            st.push(root);
            root = root->left;
        } else {
            TreeNode* node = st.top();

            // if right exists and not processed yet
            if (node->right && lastVisited != node->right) {
                root = node->right;
            } else {
                res.push_back(node->val);
                lastVisited = node;
                st.pop();
            }
        }
    }

    return res;
}
