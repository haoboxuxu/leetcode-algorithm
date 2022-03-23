class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        auto pH = new ListNode(-1), qH = new ListNode(-1);
        auto p = pH, q = qH, cur = head;
        bool flag = true;
        while (cur) {
            if (flag) {
                p = p->next = cur;
            } else {
                q = q->next = cur;
            }
            flag = !flag;
            cur = cur->next;
        }
        p->next = qH->next;
        q->next = nullptr;
        return pH->next;
    }
};