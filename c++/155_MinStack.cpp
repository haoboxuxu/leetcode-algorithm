class MinStack {
public:
    stack<int> a, b;
    MinStack() {
    }
    
    void push(int val) {
        a.push(val);
        if (b.empty() || b.top() >= val) b.push(val);
    }
    
    void pop() {
        if (b.top() == a.top()) b.pop();
        a.pop();
    }
    
    int top() {
        return a.top();
    }
    
    int getMin() {
        return b.top();
    }
};