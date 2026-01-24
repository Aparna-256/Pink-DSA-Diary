class Solution{
    public:
    Node* LCA(Node* root, Node* p, Node* q){
        
        Node* curr = root;
        
        while(curr!=NULL){

        if(curr->val < p->val && curr->val < q->val){
            curr = curr->right;
        }
        else if(curr->val > p->val && curr->val >q->val){
            curr = curr->left;
        }
        else{
            return curr;
        }
        }
        
        return NULL;
    }
}