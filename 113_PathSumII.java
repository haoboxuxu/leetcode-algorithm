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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res = new ArrayList<>();
        return dfs(root, sum, res, new ArrayList<Integer>());
    }

    private List<List<Integer>> dfs(TreeNode node, int sum, List<List<Integer>> res, List<Integer> path) {
        if (node == null) {
            return res;
        }
        if (node.left == null && node.right == null) {
            if (sum == node.val) {
                path.add(node.val);
                res.add(new ArrayList<>(path));
                path.remove(path.size() - 1);
            }
            return res;
        }
        path.add(node.val);
        dfs(node.left, sum - node.val, res, path);
        dfs(node.right, sum - node.val, res, path);
        path.remove(path.size() - 1);
        return res;
    }
}
