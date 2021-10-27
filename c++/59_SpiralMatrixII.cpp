class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int l = 0, r = n-1, t = 0, b = n-1;
        for (int num = 1; num <= n*n; ) {
            for (int i = l; i <= r; i++) res[t][i] = num++;
            t++;
            for (int i = t; i <= b; i++) res[i][r] = num++;
            r--;
            for (int i = r; i >= l; i--) res[b][i] = num++;
            b--;
            for (int i = b; i >= t; i--) res[i][l] = num++;
            l++;
        }
        
        return res;
    }
};
