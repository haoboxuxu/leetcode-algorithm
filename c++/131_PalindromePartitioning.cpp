class Solution {
public:
    vector<vector<bool>> dp;
    vector<vector<string>> res;
    vector<string> tmp;
    int len;
    vector<vector<string>> partition(string s) {
        len = s.length();
        dp.assign(len, vector<bool>(len, true));
        
        for (int i = len-1; i >= 0; i--) {
            for (int j = i+1; j < len; j++) {
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }
        
        dfs(s, 0);
        
        return res;
    }
    
    void dfs(const string& s, int i) {
        if (i == len) {
            res.push_back(tmp);
            return;
        }
        for (int j = i; j < len; j++) {
            if (dp[i][j]) {
                tmp.push_back(s.substr(i, j-i+1));
                dfs(s, j+1);
                tmp.pop_back();
            }
        }
    }
};
