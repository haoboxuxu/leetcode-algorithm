class Solution {
public:
    vector<string> res;
    vector<bool> vis;
    
    vector<string> permutation(string s) {
        vis.resize(s.length());
        for (int i = 0; i < s.length(); i++) vis[i] = false;
        sort(s.begin(), s.end());
        string path;
        dfs(s, 0, path);
        return res;
    }
    
    void dfs(string& s, int idx, string& path) {
        if (idx == s.length()) {
            res.push_back(path);
            return;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (i > 0 && !vis[i - 1] && s[i - 1] == s[i]) {
                continue;
            }
            if (!vis[i]) {
                path.push_back(s[i]);
                vis[i] = true;
                dfs(s, idx+1, path);
                path.pop_back();
                vis[i] = false;
            }
        }
    }
};
