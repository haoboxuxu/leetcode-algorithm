class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) return root;
        auto l = mirrorTree(root->left);
        auto r = mirrorTree(root->right);
        root->left = r, root->right = l;
        return root;
    }
};