class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            if (q.size() && i-k+1 > q.front()) q.pop_front();
            while (q.size() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            if (i >= k-1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};
