class Solution{
public:
    int ceilValue(TreeNode* root, int val){
        int ceil = -1;

        while(root != NULL){
            if(root->val == val){
                return root->val;
            }
            else if(root->val > val){
                ceil = root->val;      // possible ceil
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return ceil;
    }
};
