/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;

    void solve(TreeNode* root) {
        if (root == NULL) return;

        // Step 1: Go to right
        solve(root->right);

        // Step 2: Update node
        root->val += sum;
        sum = root->val;

        // Step 3: Go to left
        solve(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        solve(root);
        return root;
    }
};
