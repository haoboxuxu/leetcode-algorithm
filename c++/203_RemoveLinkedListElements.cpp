class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;
        head->next = removeElements(head->next, val);
        if (head->val == val) {
            return head->next;
        } else {
            return head;
        }
    }
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        for (auto p = dummy; p; p = p->next) {
            auto q = p->next;;
            while (q && q->val == val) q = q->next;
            p->next = q;
        }
        return dummy->next;
    }
};