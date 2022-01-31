class Solution {
public:
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() -1);
    }
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr) {
        if (il > ir) return nullptr;
        auto root = new TreeNode(postorder[pr]);
        int k = mp[postorder[pr]];
        root->left = build(inorder, postorder, il, k-1, pl, pl+k-1-il);
        root->right = build(inorder, postorder, k+1, ir, pl+k-il, pr-1);
        return root;
    }
};
