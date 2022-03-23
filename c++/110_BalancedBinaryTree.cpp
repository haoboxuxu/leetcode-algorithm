class Solution {
public:
    bool res;
    bool isBalanced(TreeNode* root) {
        res = true;
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int lh = dfs(root->left), rh = dfs(root->right);
        if (abs(lh - rh) > 1) res = false;
        return max(lh, rh) + 1;
    }
};