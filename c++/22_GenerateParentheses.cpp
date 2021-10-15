class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, n, n, "");
        return res;
    }
    void dfs(vector<string>& res, int l, int r, string s) {
        if (l < 0 || r < 0 || l > r) return;
        if (l == 0 && r == 0) res.push_back(s);
        dfs(res, l-1, r, s+"(");
        dfs(res, l, r-1, s+"(");
    }
};
