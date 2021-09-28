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
        ListNode* dummy = new ListNode(0, head);
        ListNode* t = dummy;
        while (t->next != nullptr) {
            if (t->next->val == val) {
                t->next = t->next->next;
            } else {
                t = t->next;
            }
        }
        
        return dummy->next;
    }
};
