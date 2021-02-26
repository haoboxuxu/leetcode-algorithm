/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        int len = getListLen(head);
        ListNode* cur = dummy;
        for (int i = 0; i < len - n; i++) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
    
    int getListLen(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        for (int i = 0; i < n; i++) {
            first = first->next;
        }
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        stack<ListNode*> stk;
        ListNode* cur = dummy;
        while (cur != nullptr) {
            stk.push(cur);
            cur = cur->next;
        }
        for (int i = 0; i < n; i++) {
            stk.pop();
        }
        ListNode* pre = stk.top();
        pre->next = pre->next->next;
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};