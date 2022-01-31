class MaxQueue {
public:
    queue<int> q;
    deque<int> dq;

    MaxQueue() {
    }
    
    int max_value() {
        if (dq.empty()) return -1;
        return dq.front();
    }
    
    void push_back(int value) {
        while (dq.size() && dq.back() < value) dq.pop_back();
        dq.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if (q.empty()) return -1;
        int f = q.front();
        if (f == dq.front()) dq.pop_front();
        q.pop();
        return f;
    }
};
