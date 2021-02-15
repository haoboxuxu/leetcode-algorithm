class Solution {
    private int n;
    public int findCircleNum(int[][] M) {
        if (M == null || M.length == 0) return 0;
        n = M.length;
        boolean[] vis = new boolean[n];
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(M, vis, i);
                res += 1;
            }
        }
        return res;
    }

    void dfs(int[][] M, boolean[] vis, int i) {
        if (vis[i]) {
            return;
        }
        vis[i] = true;
        for (int j = 0; j < n; j++) {
            if (M[i][j] == 1 && !vis[j]) {
                dfs(M, vis, j);
            }
        }
    }
}
