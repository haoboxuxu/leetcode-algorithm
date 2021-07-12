// sol1
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        while (head != nullptr) {
            if (st.count(head)) {
                return head;
            }
            st.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};
// sol2
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        
        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            
            if (fast == slow) {
                ListNode *p = head;
                while (p != slow) {
                    slow = slow->next;
                    p = p->next;
                }
                return p;
            }
        }
        return nullptr;
    }
};
