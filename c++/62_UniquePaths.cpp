class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(2, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i || !j) dp[i & 1][j] = 1;
                else dp[i & 1][j] = dp[i - 1 & 1][j] + dp[i & 1][j - 1];
            }
        }
        return dp[m - 1 & 1][n - 1];
    }
};