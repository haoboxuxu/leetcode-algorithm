class Solution {
public:
    unordered_set<int> s;

    bool findTarget(TreeNode* root, int k) {
        return dfs(root, k);
    }

    bool dfs(TreeNode* root, int k) {
        if (!root) return false;
        if (dfs(root->left, k)) return true;
        int x = root->val;
        if (s.count(k - x)) return true;
        s.insert(x);
        if (dfs(root->right, k)) return true;
        return false;
    }
};
