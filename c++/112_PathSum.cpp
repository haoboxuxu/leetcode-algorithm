class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        targetSum -= root->val;
        if (!root->left && !root->right) return targetSum == 0;
        else return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};