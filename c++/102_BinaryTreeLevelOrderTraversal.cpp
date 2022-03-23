class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                auto t = q.front();
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                level.push_back(t->val);
            }
            res.push_back(level);
        }
        return res;
    }
};