class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int n = 0;
        for (auto p = head; p; p = p->next) n++;
        
        for (int i = 1; i < n; i *= 2) {
            auto dummy = new ListNode(-1), cur = dummy;
            for (int j = 1; j <= n; j += i * 2) {
                auto l1 = head, l2 = l1;
                for (int k = 0; k < i && l2; k++) l2 = l2->next;
                
                auto o = l2;
                for (int k = 0; k < i && o; k++) o = o->next;
                
                int l = 0, r = 0;
                while (l < i && r < i && l1 && l2) {
                    if (l1->val <= l2->val) cur = cur->next = l1, l1 = l1->next, l++;
                    else cur = cur->next = l2, l2 = l2->next, r++;
                }
                
                while (l < i && l1) cur = cur->next = l1, l1 = l1->next, l++;
                while (r < i && l2) cur = cur->next = l2, l2 = l2->next, r++;
                head = o;
            }
            
            cur->next = nullptr;
            head = dummy->next;
        }
        
        return head;
    }
};
