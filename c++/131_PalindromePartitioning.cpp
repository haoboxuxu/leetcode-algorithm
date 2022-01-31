class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<bool>> dp;
    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp = vector<vector<bool>>(n, vector<bool>(n));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= j; i++) {
                if (i == j) {
                    dp[i][j] = true;
                } else if (s[i] == s[j]) {
                    if (i + 1 > j - 1 || dp[i + 1][j - 1]) dp[i][j] = true;
                }
            }
        }
        dfs(s, 0);
        return res;
    }

    void dfs(string& s, int u) {
        if (u == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = u; i < s.size(); i++) {
            if (dp[u][i]) {
                path.push_back(s.substr(u, i - u + 1));
                dfs(s, i+1);
                path.pop_back();
            }
        }
    }
};
