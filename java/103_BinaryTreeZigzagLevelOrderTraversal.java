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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) {
            return new ArrayList<List<Integer>>();
        }
        List<List<Integer>> res = new ArrayList<>();
        dfs(root, 0, res);
        return res;
    }

    public void dfs(TreeNode node, int deep, List<List<Integer>> res) {
        if (deep == res.size()) {
            List<Integer> newList = new LinkedList<>();
            newList.add(node.val);
            res.add(newList);
        }else {
            if (deep % 2 == 0) {
                res.get(deep).add(node.val);
            }else {
                res.get(deep).add(0, node.val);
            }
        }
        if (node.left != null) {
            dfs(node.left, deep+1, res);
        }
        if (node.right != null) {
            dfs(node.right, deep+1, res);
        } 
    }
}
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) {
            return new ArrayList<List<Integer>>();
        }
        List<List<Integer>> res = new ArrayList<>();

        LinkedList<TreeNode> q = new LinkedList<>();
        q.addLast(root);
        q.addLast(null);

        LinkedList<Integer> levelList = new LinkedList<>();
        boolean flag = true;

        while (q.size() > 0) {
            TreeNode cur = q.pollFirst();
            if (cur != null) {
                if (flag) {
                    levelList.addLast(cur.val);
                }else {
                    levelList.addFirst(cur.val);
                }
                if (cur.left != null) {
                    q.addLast(cur.left);
                }
                if (cur.right != null) {
                    q.addLast(cur.right);
                }
            }else {
                res.add(levelList);
                levelList = new LinkedList<>();
                if (q.size() > 0) {
                    q.addLast(null);
                }
                flag = !flag;
            }
        }

        return res;
    }
}
