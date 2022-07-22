class Solution {
public:
    int n;
    vector<bool> col, dg, udg;
    vector<vector<string>> res;
    vector<string> path;

    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        col = vector<bool>(n);
        dg = vector<bool>(2 * n);
        udg = vector<bool>(2 * n);
        path = vector<string>(n, string(n, '.'));
        dfs(0);
        return res;
    }

    void dfs(int u) {
        if (u == n) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !dg[u - i + n] && !udg[u + i]) {
                col[i] = dg[u - i + n] = udg[u + i] = true;
                path[u][i] = 'Q';
                dfs(u + 1);
                col[i] = dg[u - i + n] = udg[u + i] = false;
                path[u][i] = '.';
            }
        }
    }
};
