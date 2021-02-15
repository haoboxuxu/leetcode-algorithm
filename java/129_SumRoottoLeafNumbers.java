/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int sumNumbers(TreeNode root) {
        if (root == null) {
            return 0;
        }
        dfs1(root, 0);
        return dfs2(root);
    }

    // cal sum of path and store on leaf
    public void dfs1(TreeNode root, int sum) {
        if (root.left == null && root.right == null) {
            sum = sum * 10 + root.val;
            root.val = sum;
            return;
        }
        sum = sum * 10 + root.val;
        if (root.left != null) dfs1(root.left, sum);
        if (root.right != null) dfs1(root.right, sum);
    }

    // return sum of leaf
    public int dfs2(TreeNode root) {
        if (root.left == null && root.right == null) {
            return root.val;
        }
        int res = 0;
        if (root.left != null) res += dfs2(root.left);
        if (root.right != null) res += dfs2(root.right);
        return res;
    }
}
