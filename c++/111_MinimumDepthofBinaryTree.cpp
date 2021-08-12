// dfs
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;
        
        int mindepth = INT_MAX;
        if (root->left != nullptr) {
            mindepth = min(minDepth(root->left), mindepth);
        }
        if (root->right != nullptr) {
            mindepth = min(minDepth(root->right), mindepth);
        }
        
        return mindepth + 1;
    }
};
// bfs
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 1);
        
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (node->left == nullptr && node->right == nullptr) {
                return depth;
            }
            if (node->left != nullptr) {
                q.emplace(node->left, depth+1);
            }
            if (node->right != nullptr) {
                q.emplace(node->right, depth+1);
            }
        }
        
        return 0;
    }
};
