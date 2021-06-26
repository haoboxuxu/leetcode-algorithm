// sol1
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
    
    bool helper(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr || q == nullptr) {
            return false;
        }
        return (p->val == q->val) && helper(p->left, q->right) && helper(p->right, q->left);
    }
};
// sol2
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
    
    bool helper(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while (!que.empty()) {
            p = que.front();
            que.pop();
            q = que.front();
            que.pop();
            if (p == nullptr && q == nullptr) {
                continue;
            }
            if ((p == nullptr || q == nullptr) || (p->val != q->val)) {
                return false;
            }
            
            que.push(p->left);
            que.push(q->right);
            
            que.push(p->right);
            que.push(q->left);
        }
        return true;
    }
};
