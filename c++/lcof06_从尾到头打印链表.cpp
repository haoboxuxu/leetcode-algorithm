class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        dfs(res, head);
        return res;
    }
    
    void dfs(vector<int>& res, ListNode* head) {
        if (head == nullptr) return;
        dfs(res, head->next);
        res.push_back(head->val);
    }
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> stk;
        vector<int> res;
        ListNode* pre = head;
        while (pre != nullptr) {
            stk.push(pre->val);
            pre = pre->next;
        }
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        while (head != nullptr) {
            res.insert(res.begin(), head->val);
            head = head->next;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        int len = getLen(head);
        res.resize(len);
        while (head != nullptr) {
            res[--len] = head->val;
            head = head->next;
        }
        return res;
    }
    
    int getLen(ListNode* head) {
        int len = 0;
        while (head != nullptr) {
            len++;
            head = head->next;
        }
        return len;
    }
};