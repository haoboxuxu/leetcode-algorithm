class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(2, vector<int>(n+1, INT_MAX));
        dp[0][0] = dp[1][0] = 0;
        for (int j = 1; j <= n; j++) dp[0][j] = j;
        
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= j; i++) {
                dp[1][j] = min(dp[1][j], max(dp[0][i - 1] + 1, dp[1][j - i] + 1));
            }
        }
        return dp[1][n];
    }
};
