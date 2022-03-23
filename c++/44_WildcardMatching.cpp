class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        dp[0][0] = true;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j] == '*') {
                    dp[i][j] = dp[i][j - 1] || i && dp[i - 1][j];
                } else {
                    dp[i][j] = (s[i] == p[j] || p[j] == '?') && i && dp[i - 1][j - 1];
                    dp[i][j] = (s[i] == p[j] || p[j] == '?') && i && dp[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};
