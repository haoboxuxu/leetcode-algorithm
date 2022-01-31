class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        for (int i = 1, j = 0; i < n; i++) {
            while (j + nums[j] < i) j++;
            dp[i] = dp[j] + 1;
        }
        return dp[n-1];
    }
};
