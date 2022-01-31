class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        auto l = root->left, r = root->right;
        int lc = 1, rc = 1;
        while (l) l = l->left, lc++;
        while (r) r = r->right, rc++;
        if (lc == rc) return (1 << lc) - 1;
        return countNodes(root->left) + 1 + countNodes(root->right);
    }
};