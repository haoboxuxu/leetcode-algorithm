class Solution {
public:
    int n;
    vector<bool> col, dg, udg;
    int totalNQueens(int _n) {
        n = _n;
        col = vector<bool>(n);
        dg = vector<bool>(n);
        udg = vector<bool>(n);
        return dfs(0);
    }

    int dfs(int u) {
        if (u == n) {
            return 1;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!col[i] && !dg[u - i + n] && !udg[u + i]) {
                col[i] = dg[u - i + n] = udg[u + i] = true;
                res += dfs(u + 1);
                col[i] = dg[u - i + n] = udg[u + i] = false;
            }
        }
        return res;
    }
};
