# [剑指 Offer 07. 重建二叉树](https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/)

输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7


限制：

0 <= 节点个数 <= 5000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

```c++
class Solution {
public:
    unordered_map<int, int> map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = (int)preorder.size();
        for (int i = 0; i < size; i++) {
            map[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, size-1, 0);
    }
    
    TreeNode* helper(const vector<int>& preorder, const vector<int>& inorder,
                     int left, int right, int rootID) {
        if (left > right) {
            return nullptr;
        }
        int val = preorder[rootID];
        TreeNode* node = new TreeNode(val);
        int p = map[val];
        node->left = helper(preorder, inorder, left, p-1, rootID+1);
        node->right = helper(preorder, inorder, p+1, right, rootID+1+p-left);
        return node;
    }
};
```

