class Solution {
public:
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int res, m, n, k;
    vector<vector<bool>> vis;
    int movingCount(int _m, int _n, int _k) {
        m = _m, n = _n, k = _k;
        vis = vector<vector<bool>>(m, vector<bool>(n));
        dfs(0, 0);
        return res;
    }

    void dfs(int x, int y) {
        vis[x][y] = true;
        res += 1;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= m || b < 0 || b >= n || vis[a][b] || getSum(a) + getSum(b) > k) continue;
            dfs(a, b);
        }
    }

    int getSum(int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
};