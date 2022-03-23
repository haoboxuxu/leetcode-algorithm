class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return res;
    }

    void dfs(int n, int k, int start) {
        if (k == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i <= n; i++) {
            path.push_back(i);
            dfs(n, k - 1, i + 1);
            path.pop_back();
        }
    }
};
