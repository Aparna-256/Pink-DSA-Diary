#include <iostream>
using namespace std

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;

    }

    void insertAtEnd(Node* &head, int val){
        //create the node
        Node* newnode =new Node(val);
        if(head == NULL){
            head = newnode;
            return;
        }
        Node* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = newnode;
        newnode->prev = tail;
    }
}