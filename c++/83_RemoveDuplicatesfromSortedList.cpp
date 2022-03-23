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