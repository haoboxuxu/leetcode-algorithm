class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        auto a = head, b = head->next;
        while (b) {
            auto nxt = b->next;
            b->next = a;
            a = b;
            b = nxt;
        }
        head->next = nullptr;
        return a;
    }
};
