class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* lastSorted = head;
        ListNode* cur = head->next;
        
        while (cur != nullptr) {
            if (lastSorted->val <= cur->val) {
                lastSorted = lastSorted->next;
            } else {
                ListNode* d = dummy;
                while (d->next->val <= cur->val) {
                    d = d->next;
                }
                lastSorted->next = cur->next;
                cur->next = d->next;
                d->next = cur;
            }
            cur = lastSorted->next;
        }
        
        return dummy->next;
    }
};
