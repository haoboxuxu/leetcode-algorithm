class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> vis;
    
    vector<vector<int>> permute(vector<int>& nums) {
        path = vector<int>(nums.size());
        vis = vector<bool>(nums.size());
        dfs(nums, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, int u) {
        if (u == nums.size()) {
            res.push_back(path);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!vis[i]) {
                path[u] = nums[i];
                vis[i] = true;
                dfs(nums, u+1);
                vis[i] = false;
            }
        }
    }
};

