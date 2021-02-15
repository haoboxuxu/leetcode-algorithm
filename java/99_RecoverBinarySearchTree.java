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
    private TreeNode fiErr = null;
    private TreeNode seErr = null;
    private TreeNode prev = null;

    public void recoverTree(TreeNode root) {
        if(root == null) return;
        midOrder(root);
        nodeSwap();
    }

    public void midOrder(TreeNode root){
        if(root == null) return;
        midOrder(root.left);
        if(prev != null && prev.val > root.val){
            if(fiErr == null){
                fiErr = prev;
            }
            seErr = root;
        }
        prev = root;
        midOrder(root.right);
    }
    public void nodeSwap(){
        int temp = fiErr.val;
        fiErr.val = seErr.val;
        seErr.val = temp;
    }
}
