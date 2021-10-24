class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* pre = dummy;
        for (int i = 0; i < left - 1; i++) pre = pre->next;
        
        ListNode* r = pre;
        for (int i = 0; i < right-left+1; i++) r = r->next;
        
        ListNode* l = pre->next;
        ListNode* cur = r->next;
        
        pre->next = nullptr;
        r->next = nullptr;
        
        reverseList(l);
        
        pre->next = r;
        l->next = cur;
        return dummy->next;
    }
    
    void reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }
};
