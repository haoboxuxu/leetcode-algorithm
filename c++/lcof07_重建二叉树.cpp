class Solution {
public:
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
       return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if (pl > pr) return nullptr;
        auto root = new TreeNode(preorder[pl]);
        int k = mp[root->val];
        root->left = build(preorder, inorder, pl+1, pl+1+k-1-il, il, k-1);
        root->right = build(preorder, inorder, pr-ir+k+1, pr, k+1, ir);
        return root;
    }
};