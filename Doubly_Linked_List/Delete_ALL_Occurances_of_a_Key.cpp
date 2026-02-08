#include <iostream>
using namespace std;

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

};

Node* deleteAllOccurrences(Node* head, int k) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == k) {

            // if this is the head of the LL
            // then post deletion the head will be updated
            if (temp == head) {
                head = temp->next;
                if (head != NULL)
                    head->prev = NULL;
            }

            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;

            if (nextNode != NULL)
                nextNode->prev = prevNode;

            if (prevNode != NULL)
                prevNode->next = nextNode;

            delete temp;
            temp = nextNode;
        }
        else {
            temp = temp->next;
        }
    }

    return head;
}
