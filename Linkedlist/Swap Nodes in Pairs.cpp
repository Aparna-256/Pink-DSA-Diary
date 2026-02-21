/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* first = head;
        ListNode* sec = first->next;
        ListNode* prev = NULL;

        while(first != NULL && sec != NULL){
            ListNode* third = sec->next;

            first->next = third;
            sec->next = first;

            if(prev != NULL){
                prev->next = sec;
            }
            else{
                head = sec;
            }
            //UPDATE
            prev = first;
            first = third;
            if(first != NULL){
                sec = first->next;
            }
        }
        return head;
    }
};
