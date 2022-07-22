class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!i && !j) continue;
                else if (!i) grid[i][j] += grid[i][j - 1];
                else if (!j) grid[i][j] += grid[i - 1][j];
                else grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[n - 1][m - 1];
    }
};