#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

Node* removeDuplicates(Node* head){
    if(head == NULL){
        return head;
    }
    Node* temp = head;
    while(temp != NULL && temp->next!= NULL){

        if(temp->data == temp->next->data){

            Node* dup = temp->next;
            temp->next = temp->next->next;
            
            if(temp->next!=NULL){
                temp->next->prev = temp;

            }
            delete dup;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}