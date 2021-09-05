/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
//sol2
class MaxQueue {
public:
    MaxQueue() {
    }
    
    int max_value() {
        if (d.empty()) return -1;
        else return d.front();
    }
    
    void push_back(int value) {
        while (!d.empty() && d.back() < value) {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if (q.empty()) {
            return -1;
        }
        int res = q.front();
        if (res == d.front()) {
            d.pop_front();
        }
        q.pop();
        return res;
    }
    
private:
    queue<int> q;
    deque<int> d;
};
//sol1
class MaxQueue {
public:
    MaxQueue() {
    }
    
    int max_value() {
        int res = -1;
        for (int i = l; i != r; i++) {
            res = max(res, q[i]);
        }
        return res;
    }
    
    void push_back(int value) {
        q[r++] = value;
    }
    
    int pop_front() {
        if (l == r) return -1;
        else return q[l++];
    }
    
private:
    int q[20000];
    int l, r;
};
