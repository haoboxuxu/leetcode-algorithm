class Solution {
public:
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return res - 1;
    }
    
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        res = max(res, lh+rh+1);
        return max(lh, rh) + 1;
    }
};
