//INSERTION AT THE BEGINNING
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

    void insertAtHead(Node* &head, int val){
        //CREATE THE NODE
        Node* newnode = new Node(val);
        newnode->next = head;
    }

    if(head != NULL){
        head->prev = newnode;
    }
    head = newnode;

}