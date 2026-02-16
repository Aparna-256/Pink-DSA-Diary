class node{
    public:
    int data; 
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
}
class Solution {
public:
    void deleteNode(node* &head , int val){
        if(head ==NULL){
            return; 
        }
        if(head.data == val){
            node* temp = head; 
            head= head.next;
            delete temp;
        }
        node* curr =head;
        while(curr.next!=NULL && curr.next.data != val){
            curr = curr.next;
        }
        if(curr.next == NULL){
            cout<<"value out of range";
        }
        temp = curr.next;
        curr.next = temp.next;
        delete temp ;
    }
};
