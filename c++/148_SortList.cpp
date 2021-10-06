class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return sorting(head, nullptr);
    }
    
    ListNode* sorting(ListNode* head, ListNode* tail) {
        if (head == nullptr) return head;
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        
        ListNode* slow = head, *fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        
        ListNode* mid = slow;
        return merge(sorting(head, mid), sorting(mid, tail));
    }
    
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) temp->next = temp1;
        if (temp2 != nullptr) temp->next = temp2;
        return dummy->next;
    }
};
