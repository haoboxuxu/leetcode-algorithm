class MinStack {
public:
    stack<int> stk;
    stack<int> ms;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if (ms.empty() || ms.top() >= val) ms.push(val);
    }
    
    void pop() {
        if (ms.top() >= stk.top()) ms.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return ms.top();
    }
};
