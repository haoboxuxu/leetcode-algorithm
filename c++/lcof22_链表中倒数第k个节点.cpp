class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int n = 0;
        for (auto p = head; p; p = p->next) n++;
        auto p = head;
        for (int i = 0; i < n - k; i++) p = p->next;
        return p;
    }
};
