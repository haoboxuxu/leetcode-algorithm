class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int res = 1;
        vis[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 && j == 0) || getSum(i) + getSum(j) > k) {
                    continue;
                }
                if (i - 1 >= 0) vis[i][j] |= vis[i-1][j];
                if (j - 1 >= 0) vis[i][j] |= vis[i][j-1];
                res += vis[i][j];
            }
        }
        return res;
    }
private:
    int getSum(int x) {
        int res = 0;
        while (x != 0) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }
};
