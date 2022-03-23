class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto dummy = new ListNode(-1), cur = dummy;
        dummy->next = head;
        for (int i = 0; i < left - 1; i++) cur = cur->next;
        auto a = cur->next, b = cur->next->next;
        for (int i = left; i < right; i++) {
            auto nxt = b->next;
            b->next = a;
            a = b;
            b = nxt;
        }
        cur->next->next = b;
        cur->next = a;
        return dummy->next;
    }
};