// sol1
class Solution {
public:
#define ll long long
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
    
    bool dfs(TreeNode* root, ll l, ll r) {
        if (root == nullptr) return true;
        if (root->val <= l || root->val >= r) return false;
        return dfs(root->left, l, root->val) && dfs(root->right, root->val, r);
    }
};
// sol2
class Solution {
public:
    long long last = -1e10;
    bool isValidBST(TreeNode* root) {
        if (root) {
            if (!isValidBST(root->left)) return false;
            if (last >= root->val) return false;
            last = root->val;
            if (!isValidBST(root->right)) return false;
        }
        return true;
    }
};
