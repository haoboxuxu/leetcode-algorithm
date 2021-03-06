class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(res, nums, 0, (int)nums.size());
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& nums, int index, int len) {
        if (index == len) {
            res.emplace_back(nums);
            return;
        }
        for (int i = index; i < len; i++) {
            swap(nums[i], nums[index]);
            dfs(res, nums, index+1, len);
            swap(nums[i], nums[index]);
        }
    }
};