/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val) {
            return head->next;
        }
        ListNode *prev = head, *cur = head->next;
        while (cur != nullptr && cur->val != val) {
            prev = cur;
            cur = cur -> next;
        }
        if (cur != nullptr) {
            prev->next = cur->next;
        }
        return head;
    }
};
