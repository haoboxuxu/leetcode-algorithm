// dp
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, n = s.size();
        vector<int> f(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(' && i >= 2) {
                    f[i] = f[i - 2] + 2;
                } else if (i - f[i - 1] > 0 && s[i - f[i - 1] - 1] == '(') {
                    f[i] = f[i - 1] + 2 + ((i - f[i - 1]) >= 2 ? f[i - f[i - 1] - 2] : 0);
                }
                res = max(res, f[i]);
            }
        }
        return res;
    }
};
// stk
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int res = 0;
        for (int i = 0, start = -1; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                if (stk.size()) {
                    stk.pop();
                    if (stk.size()) {
                        res = max(res, i - stk.top());
                    } else {
                        res = max(res, i - start);
                    }
                } else {
                    start = i;
                }
            }
        }
        return res;
    }
};