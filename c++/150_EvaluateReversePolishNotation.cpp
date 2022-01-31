class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                auto b = stk.top(); stk.pop();
                auto a = stk.top(); stk.pop();
                if (t == "+") stk.push(a + b);
                if (t == "-") stk.push(a - b);
                if (t == "*") stk.push(a * b);
                if (t == "/") stk.push(a / b);
            } else {
                stk.push(stoi(t));
            }
        }
        return stk.top();
    }
};
