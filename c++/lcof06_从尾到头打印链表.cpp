class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        for (auto p = head; p; p = p->next) res.push_back(p->val);
        reverse(res.begin(), res.end());
        return res;
    }
};