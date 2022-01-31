class Solution {
public:
    bool validateStackSequences(vector<int>& a, vector<int>& b) {
        stack<int> stk;
        for (int i = 0, j = 0; i < a.size(); i++) {
            stk.push(a[i]);
            while (stk.size() && j < b.size() && stk.top() == b[j]) {
                stk.pop();
                j++;
            }
        }
        return stk.empty();
    }
};
