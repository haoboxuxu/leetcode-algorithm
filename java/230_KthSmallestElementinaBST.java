class Solution {
    public int kthSmallest(TreeNode root, int k) {
        if (root == null) {
            return 0;
        }
        Stack<TreeNode> stack = new Stack<>();
        TreeNode cur = root;
        boolean done = false;
        int count = 0;
        int res = 0;

        while (!done) {
            if (cur != null) {
                stack.push(cur);
                cur = cur.left;
            }else {
                if(stack.empty()) {
                    done = true;
                }else {
                    cur = stack.pop();
                    count += 1;
                    if (count == k) {
                        res = cur.val;
                        break;
                    }
                    cur = cur.right;
                }
            }
        }

        return res;
    }
}

/*
slow inorder
class Solution {
    public int kthSmallest(TreeNode root, int k) {
        List<Integer> arr = new ArrayList<Integer>();
        inorder(root, arr);
        
        return arr.get(k-1);
    }

    public void inorder(TreeNode root, List<Integer> arr) {
        if (root == null) {
            return;
        }
        inorder(root.left, arr);
        arr.add(root.val);
        inorder(root.right, arr);
    }
}
*/
