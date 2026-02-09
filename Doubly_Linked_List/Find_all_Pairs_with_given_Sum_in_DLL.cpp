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

Node* findTail(Node* head) {
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    return tail;
}

vector<vector<int>> findPair(Node* head, int k) {
    vector<vector<int>> ans;
    if (head == NULL) return ans;

    Node* left = head;
    Node* right = findTail(head);

    while (left != right && left->data < right->data) {
        int sum = left->data + right->data;

        if (sum == k) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (sum < k) {
            left = left->next;
        }
        else {
            right = right->prev;
        }
    }
    return ans;
}
