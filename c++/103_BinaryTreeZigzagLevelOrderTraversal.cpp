class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while (!q.empty()) {
            int size = (int)q.size();
            deque<int> tmp;
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                if (flag) tmp.push_back(node->val);
                else tmp.push_front(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(vector<int>{tmp.begin(), tmp.end()});
            flag = !flag;
        }
        return res;
    }
};
