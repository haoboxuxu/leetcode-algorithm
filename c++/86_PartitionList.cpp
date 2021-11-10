class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1 = new ListNode(0);
        ListNode* l1Head = l1;
        ListNode* l2 = new ListNode(0);
        ListNode* l2Head = l2;
        while (head != nullptr) {
            if (head->val < x) {
                l1->next = head;
                l1 = l1->next;
            } else {
                l2->next = head;
                l2 = l2->next;
            }
            head = head->next;
        }
        l2->next = nullptr;
        l1->next = l2Head->next;
        return l1Head->next;
    }
};
