class Solution {
public:
    unordered_map<int, int> mp;
    int rootid;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        rootid = n-1;
        return helper(inorder, postorder, 0, n-1);
    }
    
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int l, int r) {
        if (l > r) return nullptr;
        int val = postorder[rootid];
        TreeNode* node = new TreeNode(val);
        int p = mp[val];
        rootid--;
        node->right = helper(inorder, postorder, p+1, r);
        node->left = helper(inorder, postorder, l, p-1);
        return node;
    }
};
