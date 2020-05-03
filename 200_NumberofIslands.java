class Solution {
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0) return 0;
        int n = grid.length;
        int m = grid[0].length;
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != '0') {
                    dfs(i, j, grid, n, m);
                    res++;
                }
            }
        }
        return res;
    }

    void dfs(int i, int j, char[][] grid, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        dfs(i + 1, j, grid, n, m);
        dfs(i - 1, j, grid, n, m);
        dfs(i, j + 1, grid, n, m);
        dfs(i, j - 1, grid, n, m);
    }
}
