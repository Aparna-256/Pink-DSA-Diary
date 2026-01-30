class Solution {
public:
    node* InorderSuccessor(node* root, node* target) {
        node* ans = NULL;

        while(root) {
            if(root->val > target->val) {
                ans = root;          // possible successor
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return ans;
    }
};
