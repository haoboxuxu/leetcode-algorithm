/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root == null) {
        	return true;
        }
        else {
        	return checkLR(root.left, root.right);
        }
    }
    public boolean checkLR(TreeNode l, TreeNode r) {
		if(l == null && r == null) {
			return true;
		}
		if(l != null && r != null && l.val == r.val) {
			return checkLR(l.left, r.right) && checkLR(l.right, r.left);
		}
		return false;
	}
}
