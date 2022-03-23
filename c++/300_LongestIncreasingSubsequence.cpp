// logn
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
//n2
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};