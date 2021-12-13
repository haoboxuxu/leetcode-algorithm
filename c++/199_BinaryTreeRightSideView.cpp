class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, res, 0);
        return res;
    }
    
    void dfs(TreeNode* root, vector<int>& res, int depth) {
        if (root == nullptr) return;
        if (depth == res.size()) {
            res.push_back(root->val);
        }
        depth += 1;
        dfs(root->right, res, depth);
        dfs(root->left, res, depth);
    }
};
