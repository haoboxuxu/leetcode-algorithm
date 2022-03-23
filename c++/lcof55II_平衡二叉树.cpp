class Solution {
public:
    bool res;
    bool isBalanced(TreeNode* root) {
        res = true;
        height(root);
        return res;
    }

    int height(TreeNode* root) {
        if (!root) return 0;
        int lh = height(root->left), rh = height(root->right);
        if (abs(lh - rh) > 1) res = false;
        return max(lh ,rh) + 1;
    }
};