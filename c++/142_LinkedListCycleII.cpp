class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        auto s = head, f = head->next;
        while (1) {
            if (!f || !f->next) return nullptr;
            s = s->next, f = f->next->next;
            if (s == f) {
                s = head, f = f->next;
                while (s != f) s = s->next, f = f->next;
                return s;
            }
        }
        return nullptr;
    }
};