// sol1
#define ll long long
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    
    bool helper(TreeNode* root, ll low, ll up) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= low || root->val >= up) {
            return false;
        }
        return helper(root->left, low, root->val) && helper(root->right, root->val, up);
    }
};
// sol2
#define ll long long
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        ll prev = (ll)INT_MIN - 1;
        
        while (!stk.empty() || root != nullptr) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->val <= prev) {
                return false;
            }
            prev = root->val;
            root = root->right;
        }
        return true;
    }
};


