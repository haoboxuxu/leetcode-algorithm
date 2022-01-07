class MyQueue {
public:
    stack<int> a, b;
    MyQueue() {

    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        while (a.size() > 1) {
            b.push(a.top());
            a.pop();
        }
        int t = a.top();
        a.pop();
        while (!b.empty()) {
            a.push(b.top());
            b.pop();
        }
        return t;
    }
    
    int peek() {
        while (a.size() > 1) {
            b.push(a.top());
            a.pop();
        }
        int t = a.top();
        while (!b.empty()) {
            a.push(b.top());
            b.pop();
        }
        return t;
    }
    
    bool empty() {
        return a.empty();
    }
};
