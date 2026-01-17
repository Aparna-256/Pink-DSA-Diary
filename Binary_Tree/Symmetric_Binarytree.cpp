//leetcode 101 EASY
//BFS

class Solution {
public:
    bool isMirror(TreeNode* a, TreeNode* b) {

        // both empty → symmetric
        if (a == nullptr && b == nullptr)
            return true;

        // one empty, one not → not symmetric
        if (a == nullptr || b == nullptr)
            return false;

        // values must match
        if (a->val != b->val)
            return false;

        // mirror check
        return isMirror(a->left, b->right) &&
               isMirror(a->right, b->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
};
