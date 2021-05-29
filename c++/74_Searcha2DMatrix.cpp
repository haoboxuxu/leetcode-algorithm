class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = (int)matrix.size(), n = (int)matrix[0].size();
        
        int left = 0;
        int right = n*m-1;
        
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            int num = matrix[mid/n][mid%n];
            if (num < target) {
                left = mid + 1;
            } else if (num > target) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        
        return false;
    }
};