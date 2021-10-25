class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++) {
            string& token = tokens[i];
            if (isNum(token)) {
                stk.push(atoi(token.c_str()));
            } else {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                if (token == "+") stk.push(num1 + num2);
                if (token == "-") stk.push(num1 - num2);
                if (token == "*") stk.push(num1 * num2);
                if (token == "/") stk.push(num1 / num2);
            }
        }
        return stk.top();
    }
    
    bool isNum(string& token) {
        return !(token=="+" || token=="-" || token=="*" || token=="/");
    }
};
