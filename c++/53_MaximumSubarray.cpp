class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(dp[i], res);
        }
        return res;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(2);
        dp[0 & 1] = nums[0];
        int res = dp[0 & 1];
        for (int i = 1; i < nums.size(); i++) {
            dp[i & 1] = max(dp[i - 1 & 1] + nums[i], nums[i]);
            res = max(dp[i & 1], res);
        }
        return res;
    }
};