class Solution {
public:
    int dfs(TreeNode* node, int current) {
        if (!node) return 0;

        // Update current binary number
        current = current * 2 + node->val;

        // If it's a leaf node
        if (!node->left && !node->right)
            return current;

        // Otherwise sum from left and right
        return dfs(node->left, current) + 
               dfs(node->right, current);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};
