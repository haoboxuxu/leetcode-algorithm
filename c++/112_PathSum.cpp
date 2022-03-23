class Solution {
public:
    bool hasPathSum(TreeNode* root, int target) {
        if (!root) return false;
        target -= root->val;
        if (!root->left && !root->right) return target == 0;
        return root->left && hasPathSum(root->left, target) || root->right && hasPathSum(root->right, target);
    }
};