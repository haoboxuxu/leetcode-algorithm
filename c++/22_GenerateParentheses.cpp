class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return res;
    }

    void dfs(int n, int lc, int rc, string path) {
        if (lc == n && rc == n) {
            res.push_back(path);
            return;
        }
        if (lc < n) dfs(n, lc + 1, rc, path + '(');
        if (rc < n && lc > rc) dfs(n, lc, rc + 1, path + ')');
    }
};