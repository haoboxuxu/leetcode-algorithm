class Solution {
public:
    void flatten(TreeNode* root) {
        while (root) {
            TreeNode* p = root->left;
            if (p) {
                while (p->right) p = p->right;
                p->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* r = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode* cur = root;
        while (cur->right != nullptr) {
            cur = cur->right;
        }
        cur->right = r;
    }
};
