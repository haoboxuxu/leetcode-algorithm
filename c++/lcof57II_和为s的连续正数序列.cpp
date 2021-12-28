class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        for (int l = 1, r = 2; l < r;) {
            int sum = (l+r) * (r-l+1) / 2;
            if (sum == target) {
                tmp.clear();
                for (int i = l; i <= r; i++) tmp.push_back(i);
                res.push_back(tmp);
                l++;
            } else if (sum < target) {
                r++;
            } else {
                l++;
            }
        }
        return res;
    }
};
