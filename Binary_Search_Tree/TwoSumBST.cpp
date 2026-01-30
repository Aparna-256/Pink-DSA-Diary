//BRUTE FORCE APPROACH
class Solution {
public:
    
    void inorder(TreeNode* root, vector<TreeNode*>& nums) {
        if (root == NULL) return;
        
        inorder(root->left, nums);
        nums.push_back(root);
        inorder(root->right, nums);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<TreeNode*> nums;
        inorder(root, nums);

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left]->val + nums[right]->val;

            if (sum == k) return true;
            else if (sum < k) left++;
            else right--;
        }
        return false;
    }
};




//optimized APPROCH
class Solution {
public:
    stack<TreeNode*> st1, st2;

    void nextLeft(TreeNode* root){
        while(root){
            st1.push(root);
            root = root->left;
        }
    }

    void nextRight(TreeNode* root){
        while(root){
            st2.push(root);
            root = root->right;
        }
    }

    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        nextLeft(root);
        nextRight(root);

        while(!st1.empty() && !st2.empty() && st1.top() != st2.top()){
            int leftVal  = st1.top()->val;
            int rightVal = st2.top()->val;
            int sum = leftVal + rightVal;

            if(sum == k) return true;

            else if(sum < k){
                TreeNode* node = st1.top();
                st1.pop();
                nextLeft(node->right);
            }
            else{
                TreeNode* node = st2.top();
                st2.pop();
                nextRight(node->left);
            }
        }
        return false;
    }
};
