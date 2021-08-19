// sol1
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }
        
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};
// sol2
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        
        queue<TreeNode*> qNode;
        queue<int> qVal;
        qNode.push(root);
        qVal.push(root->val);
        
        while (!qNode.empty()) {
            TreeNode* node = qNode.front();
            int val = qVal.front();
            
            qNode.pop();
            qVal.pop();
            
            if (node->left == nullptr && node->right == nullptr) {
                if (val == targetSum) return true;
                else continue;
            }
            
            if (node->left != nullptr) {
                qNode.push(node->left);
                qVal.push(node->left->val + val);
            }
            
            if (node->right != nullptr) {
                qNode.push(node->right);
                qVal.push(node->right->val + val);
            }
        }
        
        return false;
    }
};
