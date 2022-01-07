//1queue
class MyStack {
public:
    queue<int> q;
    MyStack() {

    }
    
    void push(int x) {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int t = q.front();
        q.pop();
        return t;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

//2queue
class MyStack {
public:
    queue<int> q, w;
    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        while (q.size() > 1) {
            w.push(q.front());
            q.pop();
        }
        int t = q.front();
        q.pop();
        while (!w.empty()) {
            q.push(w.front());
            w.pop();
        }
        return t;
    }
    
    int top() {
        while (q.size() > 1) {
            w.push(q.front());
            q.pop();
        }
        int t = q.front();
        q.pop();
        while (!w.empty()) {
            q.push(w.front());
            w.pop();
        }
        q.push(t);
        return t;
    }
    
    bool empty() {
        return q.empty();
    }
};
