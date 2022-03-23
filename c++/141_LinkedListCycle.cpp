class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        auto s = head, f = head->next;
        while (s != f) {
            if (!f || !f->next) return false;
            s = s->next;
            f = f->next->next;
        }
        return true;
    }
};