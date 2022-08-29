class Solution {
public:
    int rob(TreeNode* root) {
        auto f = dfs(root);
        return max(f[0], f[1]);
    }

    vector<int> dfs(TreeNode* u) {
        if (!u) return {0, 0};
        auto x = dfs(u->left), y = dfs(u->right);
        return {max(x[0], x[1]) + max(y[0], y[1]), x[0] + y[0] + u->val};
    }
};
