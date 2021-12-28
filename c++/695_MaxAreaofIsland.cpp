class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    res = max(res, dfs(grid, i, j));
                }
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>>& grid, int x, int y) {
        int area = 1;
        grid[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size() && grid[a][b] == 1) {
                area += dfs(grid, a, b);
            }
        }
        return area;
    }
};
