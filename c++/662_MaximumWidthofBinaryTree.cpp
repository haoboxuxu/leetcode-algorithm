class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int res = 1;
        while (q.size()) {
            int sz = q.size();
            int l = q.front().second, r;
            for (int i = 0; i < sz; i++) {
                auto t = q.front();
                q.pop();
                auto v = t.first;
                auto p = t.second - l + 1;
                r = t.second;
                if (v->left) q.push({v->left, p * 2ll});
                if (v->right) q.push({v->right, p * 2ll + 1});
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
