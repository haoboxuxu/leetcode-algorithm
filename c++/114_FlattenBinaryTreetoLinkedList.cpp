class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode* cur = root;
        while (cur->right != nullptr) {
            cur = cur->right;
        }
        cur->right = tmp;
    }
};
