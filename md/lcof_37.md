# [剑指 Offer 37. 序列化二叉树](https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/)

请实现两个函数，分别用来序列化和反序列化二叉树。

示例: 

你可以将以下二叉树：

    	1
     / \
     2   3
         / \
        4   5
  

序列化为 "[1,2,3,null,null,4,5]"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

```java
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
    public static String serialize(TreeNode root) {
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
```

