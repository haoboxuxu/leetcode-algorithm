class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }
    
    void dfs(TreeNode* root, int targetSum) {
        if (root == nullptr) return;
        path.push_back(root->val);
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr && targetSum == 0) res.push_back(path);
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        path.pop_back();
    }
};
