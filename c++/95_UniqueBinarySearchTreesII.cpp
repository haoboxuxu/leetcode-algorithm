class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {nullptr};
        return dfs(1, n);
    }
    
    vector<TreeNode*> dfs(int l, int r) {
        if (l > r) return {nullptr};
        vector<TreeNode*> res;
        for (int i = l; i <= r; i++) {
            vector<TreeNode*> left = dfs(l, i-1);
            vector<TreeNode*> right = dfs(i+1, r);
            for (auto lt : left) {
                for (auto rt : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = lt;
                    root->right = rt;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
