class Solution {
public:
    int n, m;
    int res;
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) dfs(grid, i, j, 0);
            }
        }
        return res;
    }

    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

    void dfs(vector<vector<int>>& grid, int x, int y, int gold) {
        gold += grid[x][y];
        res = max(res, gold);
        int t = grid[x][y];
        grid[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && grid[a][b] != 0) dfs(grid, a, b, gold);
        }
        grid[x][y] = t;
    }
};
