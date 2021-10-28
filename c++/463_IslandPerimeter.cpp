class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) res += 4;
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if (grid[i][j] && grid[ni][nj]) res -= 1;
                    }
                }
            }
        }
        
        return res;
    }
};
