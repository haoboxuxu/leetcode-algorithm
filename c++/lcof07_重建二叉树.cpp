class Solution {
public:
    unordered_map<int, int> map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = (int)preorder.size();
        for (int i = 0; i < size; i++) {
            map[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, size-1, 0);
    }
    
    TreeNode* helper(const vector<int>& preorder, const vector<int>& inorder,
                     int left, int right, int rootID) {
        if (left > right) {
            return nullptr;
        }
        int val = preorder[rootID];
        TreeNode* node = new TreeNode(val);
        int p = map[val];
        node->left = helper(preorder, inorder, left, p-1, rootID+1);
        node->right = helper(preorder, inorder, p+1, right, rootID+1+p-left);
        return node;
    }
};