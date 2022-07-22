class Solution {
public:
    vector<string> res;
    vector<bool> vis;
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vis = vector<bool>(s.size());
        dfs(s, "", 0);
        return res;
    }

    void dfs(string& s, string path, int u) {
        if (u == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (i && s[i] == s[i - 1] && !vis[i - 1]) continue;
            if (!vis[i]) {
                vis[i] = true;
                path.push_back(s[i]);
                dfs(s, path, u + 1);
                vis[i] = false;
                path.pop_back();
            }
        }
    }
};