class Solution {
public:
    node* MergeTwoLists(node* l1, node* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        node* result;
        if (l1->val < l2->val) {
            result = l1;
            result->next = MergeTwoLists(l1->next, l2);
        } else {
            result = l2;
            result->next = MergeTwoLists(l1, l2->next);
        }
        return result;
    }
};
