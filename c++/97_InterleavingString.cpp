class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (s3.size() != n + m) return false;
        s1 = ' ' + s1, s2 = ' ' + s2, s3 = ' ' + s3;
        vector<vector<bool>> dp(n+1, vector<bool>(m+1));
        dp[0][0] = true;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i && s1[i] == s3[i + j]) dp[i][j] = dp[i - 1][j];
                if (j && s2[j] == s3[i + j]) dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }
        return dp[n][m];
    }
};
