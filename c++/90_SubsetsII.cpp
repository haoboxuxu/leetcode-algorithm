class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, int u) {
        if (u == nums.size()) {
            res.push_back(path);
            return;
        }

        int k = u + 1;
        while (k < nums.size() && nums[u] == nums[k]) k++;
        
        for (int i = 0; i <= k - u; i++) {
            dfs(nums, k);
            path.push_back(nums[u]);
        }

        for (int i = 0; i <= k - u; i++) {
            path.pop_back();
        }
    }
};