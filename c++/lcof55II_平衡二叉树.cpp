class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        else {
            return abs(getHeight(root->left) - getHeight(root->right)) <= 1
                   && isBalanced(root->left)
                   && isBalanced(root->right);
        }
    }
    
    int getHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        else return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
};
