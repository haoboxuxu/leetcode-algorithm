class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if (root) dfs(root, target);
        return res;
    }

    void dfs(TreeNode* root, int target) {
        path.push_back(root->val);
        target -= root->val;
        if (!root->left && !root->right) {
            if (target == 0) res.push_back(path);
        } else {
            if (root->left) dfs(root->left, target);
            if (root->right) dfs(root->right, target);
        }
        path.pop_back();
    }
};