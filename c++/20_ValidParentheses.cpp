class Solution {
public:
    bool isValid(string s) {
        int len = (int)s.length();
        if (len % 2 == 1) return false;
        stack<char> stk;
        
        for (char& c : s) {
            if (c == '(') stk.push(')');
            else if (c == '{') stk.push('}');
            else if (c == '[') stk.push(']');
            else if (stk.empty() || c != stk.top()) return false;
            else stk.pop();
        }
        
        return stk.empty();
    }
};