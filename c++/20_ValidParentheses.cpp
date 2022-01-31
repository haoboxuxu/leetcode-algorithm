class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') stk.push(c);
            else {
                if (c == ')' && stk.size() && stk.top() == '(') stk.pop();
                else if (c == ']' && stk.size() && stk.top() == '[') stk.pop();
                else if (c == '}' && stk.size() && stk.top() == '{') stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};
