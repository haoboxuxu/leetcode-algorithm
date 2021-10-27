//sol2
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp = 0;
        int res = nums[0];
        for (int i = 0; i < n; i++) {
            dp = max(nums[i], dp+nums[i]);
            res = max(res, dp);
        }
        return res;
    }
};
//sol1
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i], dp[i-1]+nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};
