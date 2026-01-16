// LeetCode 144 - Binary Tree Preorder Traversal
// Pattern: DFS (Preorder)
// Time: O(n), Space: O(h)

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void preorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;

        ans.push_back(root->val);      // Root
        preorder(root->left, ans);     // Left
        preorder(root->right, ans);    // Right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};
