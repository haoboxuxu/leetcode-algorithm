class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* l = mirrorTree(root->left);
        TreeNode* r = mirrorTree(root->right);
        root->right = l;
        root->left = r;
        return root;
    }
};
