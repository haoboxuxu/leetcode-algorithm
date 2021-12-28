class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        int n = e.size();
        vector<int> dp(n+2);
        sort(e.begin(), e.end());
        int res = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (e[j][0] < e[i][0] && e[j][1] < e[i][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
