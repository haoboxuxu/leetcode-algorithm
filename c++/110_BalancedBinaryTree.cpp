//sol1 top2bottom
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        } else {
            return abs(getTreeHeigt(root->left) - getTreeHeigt(root->right)) <= 1
                   && isBalanced(root->left)
                   && isBalanced(root->right);
        }
    }
    
    int getTreeHeigt(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } else {
            return max(getTreeHeigt(root->left), getTreeHeigt(root->right)) + 1;
        }
    }
};
//sol2 bottom2top
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getTreeHeigt(root) >= 0;
    }
    
    int getTreeHeigt(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftHeight = getTreeHeigt(root->left);
        int rightHeight = getTreeHeigt(root->right);
        if (leftHeight == -1 ||
            rightHeight == -1 ||
            abs(leftHeight - rightHeight) > 1) {
            return -1;
        } else {
            return max(leftHeight, rightHeight) + 1;
        }
    }
};
