class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        return dfs(root);
    }
    
    int dfs(TreeNode* node) {
        int res = 0;
        if (node->left) {
            res += isLeaf(node->left) ? node->left->val : dfs(node->left);
        }
        if (node->right && !isLeaf(node->right)) {
            res += dfs(node->right);
        }
        return res;
    }
    
    bool isLeaf(TreeNode* node) {
        return node->left == nullptr && node->right == nullptr;
    }
};
