class Solution {
private:
    int x, y, x_depth, y_depth;
    TreeNode  *x_parent, *y_parent;
public:
    bool isCousins(TreeNode* root, int x, int y) {
        this->x = x;
        this->y = y;
        dfs(root, 0, nullptr);
        return x_depth == y_depth && x_parent != y_parent;
    }
    
    void dfs(TreeNode* node, int depth, TreeNode* parent) {
        if (node == nullptr) return;
        if (node->val == x) {
            x_parent = parent;
            x_depth = depth;
        }
        if (node->val == y) {
            y_parent = parent;
            y_depth = depth;
        }
        
        dfs(node->left, depth+1, node);
        dfs(node->right, depth+1, node);
    }
};
