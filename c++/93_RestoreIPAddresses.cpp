class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0, "");
        return res;
    }
    
    void dfs(string& s, int u, int k, string path) {
        if (u == s.size()) {
            if (k == 4) {
                path.pop_back();
                res.push_back(path);
            }
            return;
        }
        if (k == 4) return;
        
        for (int i = u, num = 0; i < s.size(); i++) {
            if (i > u && s[u] == '0') break;
            num = num * 10 + s[i] - '0';
            if (num <= 255) dfs(s, i+1, k+1, path + to_string(num) + '.');
            else break;
        }
    }
};
