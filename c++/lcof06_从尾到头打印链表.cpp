class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        for (auto p = head; p; p = p->next) res.push_back(p->val);
        reverse(res.begin(), res.end());
        return res;
    }
};
class Solution {
public:
    vector<int> res;
    vector<int> reversePrint(ListNode* head) {
        if (head) {
            reversePrint(head->next);
            res.push_back(head->val);
        }
        return res;
    }
};
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        stack<int> stk;
        while (head) {
            stk.push(head->val);
            head = head->next;
        }
        while (stk.size()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};