class Solution {
public:
    int height(TreeNode* root) {
        if (!root)
            return 0;

        int leftH = height(root->left);
        int rightH = height(root->right);

        return max(leftH, rightH) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }

        int leftH = height(root->left);
        int rightH = height(root->right);

        if (abs(leftH - rightH) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
