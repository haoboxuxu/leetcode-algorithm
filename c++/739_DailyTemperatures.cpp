class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> stk;
        vector<int> res(t.size());
        for (int i = 0; i < t.size(); i++) {
            while (!stk.empty() && t[i] > t[stk.top()]) {
                int idx = stk.top();
                res[idx] = i - idx;
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};
