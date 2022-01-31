class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root || stk.size()) {
            while (root) {
                res.push_back(root->val);
                stk.push(root);
                root = root->left;
            }
            
            root = stk.top()->right;
            stk.pop();
        }
        return res;
    }
};
class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
    
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        res.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
};
