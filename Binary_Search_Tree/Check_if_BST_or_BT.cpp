//space : O(N)
//time  : O(N)

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v) {
        if(root == NULL) return;

        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);

        for(int i = 1; i < v.size(); i++) {
            if(v[i] <= v[i-1]) {
                return false;
            }
        }
        return true;
    }
};

------------------------------------------------------------

//SPACE : O(1)
//TIME  : O(N)

class Solution {
public:
    bool solve(TreeNode* root, long minVal, long maxVal) {
        if (root == NULL) return true;

        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }

        return solve(root->left, minVal, root->val) &&
               solve(root->right, root->val, maxVal);
    }

    bool isBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};

