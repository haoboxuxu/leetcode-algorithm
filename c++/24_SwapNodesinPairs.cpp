//sol1
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* headNext = head->next;
        head->next = swapPairs(headNext->next);
        headNext->next = head;
        return headNext;
    }
};
//sol2
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        for (ListNode* p = dummy; p->next && p->next->next;) {
            auto a = p->next, b = a->next;
            p->next = b;
            a->next = b->next;
            b->next = a;
            p = a;
        }
        return dummy->next;
    }
};
