//LEETCODE 958 MEDIUM
//BFS
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);

        bool wasNull = false;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                wasNull = true;
            } else {
                if (wasNull) {
                    return false; // non-null after null
                }
                q.push(node->left);
                q.push(node->right);
            }
        }

        return true;
    }
};
