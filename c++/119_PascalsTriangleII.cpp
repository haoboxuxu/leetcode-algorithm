class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> res(2, vector<int>(n+1));
        for (int i = 0; i <= n; i++) {
            res[i & 1][0] = res[i & 1][i] = 1;
            for (int j = 1; j < i; j++) {
                res[i & 1][j] = res[i - 1 & 1][j] + res[i - 1 & 1][j-1];
            }
        }
        return res[n & 1];
    }
};
