class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        while (q.size()) {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto t = q.front();
                level.push_back(t->val);
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            if (++cnt % 2 == 0) reverse(level.begin(), level.end());
            res.push_back(level);
        }
        return res;
    }
};
