/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
///new 
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        bfs(root, res, 0);
        return res;
    }

    private void bfs(TreeNode root, List<List<Integer>> res, int deep) {
        if (root == null) {
            return;
        }
        if (deep >= res.size()) {
            res.add(new ArrayList<Integer>());
        }
        res.get(deep).add(root.val);
        bfs(root.left, res, deep+1);
        bfs(root.right, res, deep+1);
    }
}
///old
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
    	List<List<Integer>> res = new ArrayList<List<Integer>>();
    	
    	if(root == null) return res;
    	
    	Queue<TreeNode> q = new LinkedList<>();
    	
    	q.offer(root);
    	
    	while(!q.isEmpty()) {
    		List<Integer> temp = new ArrayList<Integer>();
    		int size = q.size();
    		
    		for(int i = 0; i < size; i++) {
    			TreeNode node = q.poll();
    			temp.add(node.val);
    			if(node.left != null) q.offer(node.left);
    			if(node.right != null) q.offer(node.right);
    		}
    		res.add(temp);
    	}
    	
    	return res;
    }
}
