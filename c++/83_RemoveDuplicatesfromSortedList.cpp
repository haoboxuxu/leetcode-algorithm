class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        auto cur = head;
        for (auto p = head->next; p; p = p->next) {
            if (p->val != cur->val) {
                cur = cur->next = p;
            }
        }
        cur->next = nullptr;
        return head;
    }
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto p = dummy->next;
        while (p->next) {
            auto q = p->next;
            while (q && q->val == p->val) q = q->next;
            if (p->next == q) p = p->next;
            else p->next = q;
        }
        return dummy->next;
    }
};