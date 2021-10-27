class Solution {
public:
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, n-1, 0);
    }
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int l, int r, int rootid) {
        if (l > r) return nullptr;
        int val = preorder[rootid];
        TreeNode* node = new TreeNode(val);
        int p = mp[val];
        node->left = helper(preorder, inorder, l, p-1, rootid+1);
        node->right = helper(preorder, inorder, p+1, r, rootid+1+p-l);
        return node;
    }
};
