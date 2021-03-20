//c++
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int row = (int)matrix.size(), col = (int)matrix[0].size();
        int i = 0, j = col - 1;
        while (i < row && j >= 0) {
            int num = matrix[i][j];
            if (num == target) return true;
            else if (num > target) j--;
            else i++;
        }
        return false;
    }
};
