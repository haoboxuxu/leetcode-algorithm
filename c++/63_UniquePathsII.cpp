class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        if (!o.size()) return 0;
        int n = o.size(), m = o[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!o[i][j]) {
                    if (i == 0 && j == 0) dp[i][j] = 1;
                    else if (i == 0 && j) dp[i][j] += dp[i][j - 1];
                    else if (i && j == 0) dp[i][j] += dp[i - 1][j];
                    else dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
