class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int value) {
        if(root==NULL){
            return NULL;
        }
        if(value==root->val){
            return root;
        }
        if(value<root->val){
            return searchBST(root->left, value);
        }
        else{
            return searchBST(root->right, value);
        }
    }
};