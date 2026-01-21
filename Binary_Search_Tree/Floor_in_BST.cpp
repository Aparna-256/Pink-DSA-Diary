class Solution{
public:
    int floorValue(TreeNode* root, int val){
        int floor = -1;   // correct initialization

        while(root != NULL){
            if(root->val == val){
                return root->val;
            }
            else if(root->val < val){
                floor = root->val;   // possible floor
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        return floor;
    }
};
