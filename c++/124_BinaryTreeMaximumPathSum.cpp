class Solution {
public:
    int res;
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        dfs(root);
        return res;
    }
    
    int dfs(TreeNode* u) {
        if (!u) return 0;
        int left = max(0, dfs(u->left));
        int right = max(0, dfs(u->right));
        res = max(res, u->val + left + right);
        return u->val + max(left, right);
    }
};
