class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combine;
        dfs(candidates, target, res, combine, 0);
        return res;
    }
    
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& combine, int idx) {
        if (idx == candidates.size()) return;
        if (target == 0) {
            res.push_back(combine);
            return;
        }
        dfs(candidates, target, res, combine, idx+1);
        if (target - candidates[idx] >= 0) {
            combine.push_back(candidates[idx]);
            dfs(candidates, target-candidates[idx], res, combine, idx);
            combine.pop_back();
        }
    }
};
