//sol1
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; i++) {
            pq.emplace(nums[i], i);
        }
        vector<int> res;
        res.push_back(pq.top().first);
        for (int i = k; i < n; i++) {
            pq.emplace(nums[i], i);
            while (pq.top().second <= i-k) {
                pq.pop();
            }
            res.push_back(pq.top().first)
        }
        return res;
    }
};
//sol2
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        vector<int> res;
        res.push_back(nums[dq.front()]);
        for (int i = k; i < n; i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            while (dq.front() <= i - k) {
                dq.pop_front();
            }
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
