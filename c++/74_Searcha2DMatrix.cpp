class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n * m - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (matrix[mid/m][mid%m] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return matrix[l/m][l%m] == target;
    }
};
