class MinStack {
public:
    stack<int> a, b;
    MinStack() {
    }
    
    void push(int x) {
        a.push(x);
        if (b.empty() || b.top() >= x) b.push(x);
    }
    
    void pop() {
        if (b.size() && a.top() == b.top()) b.pop();
        a.pop();
    }
    
    int top() {
        return a.top();
    }
    
    int min() {
        return b.top();
    }
};