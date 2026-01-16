//LEETCODE 105 MEDIUM
class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int start, int end, int &idx) {

        if (start > end) return NULL;

        int rootVal = preorder[idx++];
        TreeNode* root = new TreeNode(rootVal);

        int pos;
        for (pos = start; pos <= end; pos++) {
            if (inorder[pos] == rootVal) break;
        }

        root->left  = solve(preorder, inorder, start, pos - 1, idx);
        root->right = solve(preorder, inorder, pos + 1, end, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return solve(preorder, inorder, 0, inorder.size() - 1, idx);
    }
};
