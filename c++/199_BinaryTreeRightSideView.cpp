class Solution {
public:
vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* root, int u) {
        if (!root) return;
        if (u == res.size()) {
            res.push_back(root->val);
        }
        u += 1;
        dfs(root->right, u);
        dfs(root->left, u);
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        while (q.size()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto t = q.front();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                if (i == size - 1) res.push_back(t->val);
                q.pop();
            }
        }
        return res;
    }
};