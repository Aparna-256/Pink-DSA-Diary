class Solution{
    public:
    //ITERATIVE APPROACH
    class Solution{
public:
    TreeNode* insertIntoBST_Iterative(TreeNode* root, int value){
        if(root == NULL){
            return new TreeNode(value);
        }

        TreeNode* curr = root;

        while(curr != NULL){
            if(value < curr->val){
                if(curr->left == NULL){
                    curr->left = new TreeNode(value);
                    break;
                }
                curr = curr->left;
            }
            else{
                if(curr->right == NULL){
                    curr->right = new TreeNode(value);
                    break;
                }
                curr = curr->right;
            }
        }
        return root;
    }


    //RECURSIVE APPROACH
    TreeNode* insertIntoBST(TreeNode* root, int value){
        if(root==NULL){
            return new TreeNode(value);
        }
        if(value<root->val){
            root->left = insertIntoBST(root->left, value);
        }
        else{
            root->right = insertIntoBST(root->right, value);
        }
        return root;
    }
}