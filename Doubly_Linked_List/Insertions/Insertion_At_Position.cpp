#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(Node*& head, int val) {
    Node* newnode = new Node(val);
    if(head != NULL) {
        newnode->next = head;
        head->prev = newnode;
    }
    head = newnode;
}

void insertAtPosition(Node*& head, int pos, int val) {
    if(pos == 1) {
        insertAtHead(head, val);
        return;
    }

    Node* temp = head;
    for(int i = 1; i < pos-1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        cout << "Invalid position\n";
        return;
    }

    Node* newnode = new Node(val);

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL) {
        temp->next->prev = newnode;
    }

    temp->next = newnode;
}
