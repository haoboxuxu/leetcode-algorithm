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
    private int res = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        maxRootSum(root);
        return res;
    }
    
    public int maxRootSum(TreeNode root) {
	if(root == null) {
	    return 0;
	}
	int curVal = root.val;
	int leftMaxSum = maxRootSum(root.left);
	int rightMaxSum = maxRootSum(root.right);
		
	if(leftMaxSum > 0) {
	    curVal += leftMaxSum;
	}
	if(rightMaxSum > 0) {
	    curVal += rightMaxSum;
	}
	if(curVal > res) {
	    res = curVal;
	}
        // return res; !错误理解题目，wa了很多次
	return Math.max(root.val, Math.max(root.val + leftMaxSum, root.val + rightMaxSum));
    }
}
