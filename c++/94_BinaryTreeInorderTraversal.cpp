class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root || stk.size()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            
            root = stk.top();
            res.push_back(root->val);
            root = root->right;
            stk.pop();
        }
        return res;
    }
};
class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
    
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }
};
