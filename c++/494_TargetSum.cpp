class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto num : nums) sum += num;
        int diff = sum - target;
        if (diff < 0 || diff % 2 != 0) return 0;
        int neg = (sum - target) / 2;
        vector<int> dp(neg+10);
        dp[0] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = neg; j >= nums[i]; j--) {
                dp[j] += dp[j-nums[i]];
            }
        }
        
        return dp[neg];
    }
};
