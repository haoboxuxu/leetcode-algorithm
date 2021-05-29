// 1: binary
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int len = (int)nums.size();
        for (int i = 0; i < (1<<len); i++) {
            vector<int> temp;
            for (int j = 0; j < len; j++) {
                if (i & (1<<j)) {
                    temp.push_back(nums[j]);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
// 2: