class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        auto h = dummy;
        for (int i = 0; i < left - 1; i++) h = h->next;
        auto a = h->next, b = a->next;
        for (int i = 0; i < right - left; i++) {
            auto nxt = b->next;
            b->next = a;
            a = b;
            b = nxt;
        }
        h->next->next = b;
        h->next = a;
        return dummy->next;
    }
};