class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root) dfs(root, targetSum);
        return res;
    }

    void dfs(TreeNode* root, int targetSum) {
        path.push_back(root->val);
        targetSum -= root->val;
        if (!root->left && !root->right) {
            if (targetSum == 0) res.push_back(path);
        } else {
            if (root->left) dfs(root->left, targetSum);
            if (root->right) dfs(root->right, targetSum);
        }
        path.pop_back();
    }
};