class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return res;
    }

    void dfs(TreeNode* root, int target) {
        if (root == nullptr) return;
        target -= root->val;
        path.push_back(root->val);
        if (target == 0 && !root->left && !root->right) {
            res.push_back(path);
        }
        dfs(root->left, target);
        dfs(root->right, target);
        path.pop_back();
    }
};