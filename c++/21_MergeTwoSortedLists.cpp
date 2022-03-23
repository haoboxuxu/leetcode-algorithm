class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto dummy = new ListNode(-1), cur = dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur = cur->next = list1;
                list1 = list1->next;
            } else {
                cur = cur->next = list2;
                list2 = list2->next;
            }
        }
        if (list1) cur->next = list1;
        if (list2) cur->next = list2;
        return dummy->next;
    }
};