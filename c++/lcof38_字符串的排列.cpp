class Solution {
public:
    vector<string> res;
    vector<bool> vis;
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vis.resize(s.size());
        dfs(s, "", 0);
        return res;
    }

    void dfs(string& s, string path, int u) {
        if (u == s.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            if (i && s[i] == s[i-1] && !vis[i-1]) continue;
            if (!vis[i]) {
                path.push_back(s[i]);
                vis[i] = true;
                dfs(s, path, u+1);
                path.pop_back();
                vis[i] = false;
            }
        }
    }
};
