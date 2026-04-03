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
---------------------------------------------------------------------------
    //DFS
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool isValid(TreeNode* root, int index, int total) {
        if (!root) return true;

        if (index >= total) return false;

        return isValid(root->left, 2 * index , total) &&
               isValid(root->right, 2 * index , total);
    }

    bool isCompleteTree(TreeNode* root) {
        int total = countNodes(root);
        return isValid(root, 1, total);
    }
};
