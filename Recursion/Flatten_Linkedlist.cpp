class Solution {
public:
    ListNode* mergeTwoLists(ListNode* L1, ListNode* L2) {
        if (L1 == NULL) return L2;
        if (L2 == NULL) return L1;

        ListNode* result;
        if (L1->val < L2->val) {
            result = L1;
            result->next = mergeTwoLists(L1->next, L2);
        } else {
            result = L2;
            result->next = mergeTwoLists(L1, L2->next);
        }
        return result;
    }

    ListNode* FlattenLinkedList(ListNode* Head) {
        // base case
        if (Head == NULL || Head->next == NULL)
            return Head;

        // flatten the rest
        ListNode* Head2 = FlattenLinkedList(Head->next);

        // merge current list with flattened list
        Head = mergeTwoLists(Head, Head2);

        return Head;
    }
};
