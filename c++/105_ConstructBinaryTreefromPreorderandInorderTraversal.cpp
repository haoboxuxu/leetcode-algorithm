class Solution {
public:
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() -1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int lr) {
        if (pl > pr) return nullptr;
        auto root = new TreeNode(preorder[pl]);
        int k = mp[preorder[pl]];
        root->left = build(preorder, inorder, pl+1, pl+k-il, il, k-1);
        root->right = build(preorder, inorder, pl+k-il+1, pr, k+1, pr);
        return root;
    }
};
