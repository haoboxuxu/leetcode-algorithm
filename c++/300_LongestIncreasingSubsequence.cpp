class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> q;
        for (auto num : nums) {
            if (q.empty() || num > q.back()) {
                q.push_back(num);
            } else {
                if (num <= q[0]) {
                    q[0] = num;
                } else {
                    int l = 0, r = q.size() - 1;
                    while (l < r) {
                        int mid = l + r + 1 >> 1;
                        if (q[mid] < num) l = mid;
                        else r = mid - 1; 
                    }
                    q[r + 1] = num;
                }
            }
        }
        return q.size();
    }
};