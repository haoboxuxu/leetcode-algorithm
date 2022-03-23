// dfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
// bfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while (q.size()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto t = q.front();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                q.pop();
            }
            res++;
        }
        return res;
    }
};