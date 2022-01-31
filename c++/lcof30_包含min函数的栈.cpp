class MinStack {
public:
    stack<int> stk;
    stack<int> ms;
    MinStack() {
    }
    
    void push(int x) {
        stk.push(x);
        if (ms.empty() || ms.top() >= x) ms.push(x);
    }
    
    void pop() {
        if (ms.top() >= stk.top()) ms.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int min() {
        return ms.top();
    }
};
