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
class Codec {
public:
    string path;

    string serialize(TreeNode* root) {
        dfs_s(root);
        return path;
    }

    void dfs_s(TreeNode* root) {
        if (!root) {
            path += "#,";
        } else {
            path += to_string(root->val) + ',';
            dfs_s(root->left);
            dfs_s(root->right);
        }
    }

    TreeNode* deserialize(string data) {
        int u = 0;
        return dfs_d(data, u);
    }

    TreeNode* dfs_d(string& data, int& u) {
        if (data[u] == '#') {
            u += 2;
            return nullptr;
        } else {
            int k = u;
            while (data[u] != ',') u++;
            auto root = new TreeNode(stoi(data.substr(k, u - k)));
            u++;
            root->left = dfs_d(data, u);
            root->right = dfs_d(data, u);
            return root;
        }
    }
};
```

