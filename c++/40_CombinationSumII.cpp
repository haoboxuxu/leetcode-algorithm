class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        dfs(c, target, 0);
        return res;
    }
    
    void dfs(vector<int>& c, int target, int u) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        if (u == c.size()) return;
        
        int k = u + 1;
        while (k < c.size() && c[k] == c[u]) k++;
        
        int cnt = k - u;
        
        for (int i = 0; c[u] * i <= target && i <= cnt; i++) {
            dfs(c, target - c[u] * i, k);
            path.push_back(c[u]);
        }
        
        for (int i = 0; c[u] * i <= target && i <= cnt; i++) {
            path.pop_back();
        }
    }
};
