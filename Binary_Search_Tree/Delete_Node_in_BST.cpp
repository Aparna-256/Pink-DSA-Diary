class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            // node found

            // no left child
            if(root->left == NULL){
                return root->right;
            }

            // no right child
            if(root->right == NULL){
                return root->left;
            }

            // two children
            TreeNode* temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }

            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};
