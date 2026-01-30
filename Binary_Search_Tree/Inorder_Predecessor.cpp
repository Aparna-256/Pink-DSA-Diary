class Solution {
public:
    node* InorderPredecessor(node* root, node* target) {
        node* ans = NULL;

        while(root) {
            if(root->val < target->val) {
                ans = root;          // possible predecessor
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return ans;
    }
};
