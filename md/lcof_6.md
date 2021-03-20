# [剑指 Offer 06. 从尾到头打印链表](https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)

输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

 

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]


限制：

0 <= 链表长度 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

```cpp
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
```

