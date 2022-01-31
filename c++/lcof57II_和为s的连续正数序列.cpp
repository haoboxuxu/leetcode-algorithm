class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        for (int i = 1, j = 1, sum = 1; i <= target; i++) {
            while (sum < target) j++, sum += j;
            if (sum == target && j > i) {
                vector<int> path;
                for (int k = i; k <= j; k++) path.push_back(k);
                res.push_back(path);
            }
            sum -= i;
        }
        return res;
    }
};