class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (dq.size() && i-k+1 > dq.front()) dq.pop_front();
            while (dq.size() && nums[i] >= nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            if (i >= k-1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
