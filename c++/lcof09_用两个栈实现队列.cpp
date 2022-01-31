class CQueue {
public:
    stack<int> a, b;
    CQueue() {
    }
    
    void appendTail(int value) {
        a.push(value);
    }
    
    int deleteHead() {
        if (a.empty()) return -1;
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
};