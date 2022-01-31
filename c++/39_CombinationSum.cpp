class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        dfs(c, target, 0);
        return res;
    }
    
    void dfs(vector<int>& c, int target, int u) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        if (u == c.size()) return;
        
        for (int i = 0; c[u] * i <= target; i++) {
            dfs(c, target - c[u] * i, u + 1);
            path.push_back(c[u]);
        }
        
        for (int i = 0; c[u] * i <= target; i++) {
            path.pop_back();
        }
    }
};
