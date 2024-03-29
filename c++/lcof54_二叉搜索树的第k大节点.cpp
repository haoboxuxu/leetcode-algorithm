class Solution {
public:
    int res, k;
    int kthLargest(TreeNode* root, int _k) {
        k = _k;
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->right);
        if (k == 0) return;
        if (--k == 0) res = root->val;
        dfs(root->left);
    }
};