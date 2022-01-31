class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        for (auto p = dummy; p; p = p->next) {
            if (p->next && p->next->val == val) {
                p->next = p->next->next;
            }
        }
        return dummy->next;
    }
};