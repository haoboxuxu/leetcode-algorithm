class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        if (matrix.empty()) return {};
        
        int n = (int)matrix.size(), m = (int)matrix[0].size();
        
        vector<int> res(n*m);
        
        int up = 0, down = n-1, left = 0, right = m-1;
        
        int index = 0;
        
        while (1) {
            for (int i = left; i<= right; i++) { //右
                res[index++] = matrix[up][i];
            }
            if (++up > down) break;
            for (int i = up; i <= down; i++) { //下
                res[index++] = matrix[i][right];
            }
            if (--right < left) break;
            for (int i = right; i >= left; --i) { // 左
                res[index++] = matrix[down][i];
            }
            if (--down < up) break;
            for(int i = down; i >= up; --i) { //上
                res[index++] = matrix[i][left];
            }
            if(++left > right) break;
        }
        
        return res;
    }
};