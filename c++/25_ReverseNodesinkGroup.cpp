class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto pre = dummy;
        while (head) {
            auto tail = pre;
            
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) return dummy->next;
            }
            
            auto nxt = tail->next;
            
            auto pir = reverse(head, tail);
            head = pir.first, tail = pir.second;
            
            pre->next = head;
            tail->next = nxt;
            
            pre = tail;
            head = tail->next;
        }
        return dummy->next;
    }
    
    pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail) {
        auto a = head, b = head->next, h = head;
        while (a != tail) {
            auto nxt = b->next;
            b->next = a;
            a = b;
            b = nxt;
        }
        return {a, h};
    }
};
