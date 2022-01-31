class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        for (auto p = head; p; p = p->next) len++;
        
        auto dummy = new ListNode(-1);
        dummy->next = head;
        
        auto p = dummy;
        for (int i = 0; i < len - n; i++) p = p->next;
        
        p->next = p->next->next;
        return dummy->next;
    }
};
