class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[0] = dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            int curMax = 0;
            for (int j = 1; j < i; j++) {
                curMax = max(curMax, max(j*(i-j), j*dp[i-j]));
            }
            dp[i] = curMax;
        }
        return dp[n];
    }
};
