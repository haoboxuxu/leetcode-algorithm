class Solution {
    HashMap<Integer, Integer> map = new HashMap<>();
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        for (int i = 0; i < inorder.length; i++) {
            map.put(inorder[i], i);
        }
        return dfs(preorder, inorder, 0, inorder.length - 1, 0);
    }

    private TreeNode dfs(int[] preorder, int[] inorder, int l, int r, int rootID) {
        if (l > r) {
            return null;
        }
        int val = preorder[rootID];
        TreeNode node = new TreeNode(val);
        int p = map.get(val);
        node.left = dfs(preorder, inorder, l, p - 1, rootID + 1);
        node.right = dfs(preorder, inorder, p + 1, r, rootID + 1 + (p - l));
        return node;
    }
}
