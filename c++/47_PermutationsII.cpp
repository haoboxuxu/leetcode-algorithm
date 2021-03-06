class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        int len = (int)nums.size();
        vis.resize(len);
        sort(nums.begin(), nums.end());
        dfs(res, nums, 0, perm);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& nums, int index, vector<int>& perm) {
        if (index == nums.size()) {
            res.emplace_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (vis[i] || (i > 0 && nums[i] == nums[i-1] && !vis[i-1])) {
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = true;
            dfs(res, nums, index+1, perm);
            vis[i] = false;
            perm.pop_back();
        }
    }
private:
    vector<bool> vis;
};