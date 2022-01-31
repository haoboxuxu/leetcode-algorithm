class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> heights(n, vector<int>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    if (i) heights[i][j] = heights[i-1][j] + 1;
                    else heights[i][j] = 1;
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, largestRectangleArea(heights[i]));
        }
        return res;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (stk.size() && heights[stk.top()] >= heights[i]) stk.pop();
            if (stk.empty()) left[i] = -1;
            else left[i] = stk.top();
            stk.push(i);
        }
        
        stk = stack<int>();
        
        for (int i = n - 1; i >= 0; i--) {
            while (stk.size() && heights[stk.top()] >= heights[i]) stk.pop();
            if (stk.empty()) right[i] = n;
            else right[i] = stk.top();
            stk.push(i);
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        }
        return res;
    }
};
