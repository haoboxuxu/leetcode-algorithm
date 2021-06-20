class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) return head;
        
        int len = 1;
        ListNode* iter = head;
        while (iter->next != nullptr) {
            len += 1;
            iter = iter->next;
        }
        
        int skip = len - k % len;
        
        iter->next = head;
        
        while (skip--) {
            iter = iter->next;
        }
        
        ListNode* res = iter->next;
        iter->next = nullptr;
        return res;
    }
};
