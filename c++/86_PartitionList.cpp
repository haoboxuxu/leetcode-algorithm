class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        auto lh = new ListNode(-1), rh = new ListNode(-1);
        auto lc = lh, rc = rh;
        for (auto p = head; p; p = p->next) {
            if (p->val < x) lc = lc->next = p;
            else rc = rc->next = p;
        }
        lc->next = rh->next;
        rc->next = nullptr;
        return lh->next;
    }
};