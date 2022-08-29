class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        int n = 0;
        for (auto p = head; p; p = p->next) n++;

        auto mid = head;
        for (int i = 0; i < (n + 1) / 2 - 1; i++) mid = mid->next; // 求mid

        auto a = mid, b = a->next;
        for (int i = 0; i < n / 2; i++) { // 反转后半部分
            auto nxt = b->next;
            b->next = a;
            a = b, b = nxt;
        }
        
        auto p = head, q = a; //头和尾
        for (int i = 0; i < n / 2; i++) {
            auto qnxt = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next, q = qnxt;
        }

        if (n & 1) mid->next = nullptr;
        else mid->next->next = nullptr;
    }
};