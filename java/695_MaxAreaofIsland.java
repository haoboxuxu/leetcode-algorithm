class Solution {
    int area = 0;
    public int maxAreaOfIsland(int[][] grid) {
        if(grid == null || grid.length == 0) return 0;
        int n = grid.length;
        int m = grid[0].length;
        int res = 0;
        boolean[][] vis = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] || grid[i][j] == 0) {
                    continue;
                }
                area = 0;
                dfs(i, j, grid, vis, n, m);
                res = Math.max(area, res);
            }
        }

        return res;
    }
    void dfs(int i, int j, int[][] grid, boolean[][] vis, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j]) {
            return;
        }
        if (grid[i][j] == 0) {
            vis[i][j] = true;
            return;
        }
        vis[i][j] = true;
        area++;
        dfs(i+1, j, grid, vis, n, m);
        dfs(i-1, j, grid, vis, n, m);
        dfs(i, j+1, grid, vis, n, m);
        dfs(i, j-1, grid, vis, n, m);
    }
}
