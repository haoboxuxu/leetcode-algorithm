/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        String str = "";
        if (root == null) {
            return str;
        }
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            TreeNode cur = q.remove();
            if (cur == null) {
                str += "null,";
            }else {
                str += cur.val + ",";
                q.add(cur.left);
                q.add(cur.right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data.length() == 0) {
            return null;
        }
        String[] arr = data.split(",");

        Queue<TreeNode> q = new LinkedList<>();
        TreeNode root = new TreeNode(Integer.valueOf(arr[0]));
        q.add(root);

        for (int i = 1; i < arr.length; i++) {
            TreeNode cur = q.poll();
            if (!arr[i].equals("null")) {
                TreeNode left = new TreeNode(Integer.valueOf(arr[i]));
                cur.left = left;
                q.add(left);
            }
            i += 1;
            if (i < arr.length && !arr[i].equals("null")) {
                TreeNode right = new TreeNode(Integer.valueOf(arr[i]));
                cur.right = right;
                q.add(right);
            }
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
