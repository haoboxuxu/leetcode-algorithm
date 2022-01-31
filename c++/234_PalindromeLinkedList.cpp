class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n = 0;
        for (auto p = head; p; p = p->next) n++;
        if (n <= 1) return true;
        int half = n / 2;
        auto a = head;
        for (int i = 0; i < n - half; i++) a = a->next;

        auto b = a->next;
        for (int i = 0; i < half - 1; i++) {
            auto nxt = b->next;
            b->next = a;
            a = b, b = nxt;
        }

        auto p = head, q = a;
        bool res = true;
        for (int i = 0; i < half; i++) {
            if (p->val != q->val) {
                res = false;
                break;
            }
            p = p->next, q = q->next;
        }

        auto tail = a;
        b = a->next;
        for (int i = 1; i < half - 1; i++) {
            auto nxt = b->next;
            b->next = a;
            a = b;
            b = nxt;
        }
        tail->next = nullptr;
        return res;
    }
};