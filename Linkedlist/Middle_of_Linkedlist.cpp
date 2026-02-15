class Solution {
public:
    ListNode* middleNode(ListNode* head) {   // <-- rename here
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // move 1 step
            fast = fast->next->next;    // move 2 steps
        }

        return slow; // slow will be at the middle node
    }
};