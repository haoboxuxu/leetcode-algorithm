class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = new ListNode(0);
        ListNode* evenHead = new ListNode(0);
        ListNode* odd = oddHead;
        ListNode* even = evenHead;
        
        
        ListNode* cur = head;
        bool flag = true;
        
        while (cur != nullptr) {
            if (flag) {
                odd->next = cur;
                odd = odd->next;
            } else {
                even->next = cur;
                even = even->next;
            }
            cur = cur->next;
            flag = !flag;
        }
        
        odd->next = evenHead->next;
        even->next = nullptr;
        
        return oddHead->next;
    }
};
