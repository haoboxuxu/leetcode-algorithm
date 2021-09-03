# Serialize and Deserialize Binary Tree

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

**Clarification:** The input/output format is the same as [how LeetCode serializes a binary tree](https://leetcode.com/faq/#binary-tree). You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/15/serdeser.jpg)

```
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
```

**Example 2:**

```
Input: root = []
Output: []
```

**Example 3:**

```
Input: root = [1]
Output: [1]
```

**Example 4:**

```
Input: root = [1,2]
Output: [1,2]
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[0, 104]`.
- `-1000 <= Node.val <= 1000`

```c++
// sol1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfs(root, res);
        return res;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> list_data;
        string str;
        for (auto& c : data) {
            if (c == ',') {
                list_data.push_back(str);
                str.clear();
            } else {
                str.push_back(c);
            }
        }
        if (!str.empty()) {
            list_data.push_back(str);
            str.clear();
        }
        return recover(list_data);
    }
    
    void dfs(TreeNode* root, string& str) {
        if (root == nullptr) {
            str += "#,";
        } else {
            str += to_string(root->val) + ",";
            dfs(root->left, str);
            dfs(root->right, str);
        }
    }
    
    TreeNode* recover(list<string>& list_data) {
        if (list_data.front() == "#") {
            list_data.erase(list_data.begin());
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(stoi(list_data.front()));
        list_data.erase(list_data.begin());
        node->left = recover(list_data);
        node->right = recover(list_data);
        return node;
    }
};
// sol2
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "X";
        }
        string left = "(" + serialize(root->left) + ")";
        string right = "(" + serialize(root->right) + ")";
        return left + to_string(root->val) + right;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int ptr = 0;
        return parse(data, ptr);
    }
    
    TreeNode* parseSubtree(string& data, int& ptr) {
        ptr += 1; //跳过左括号
        TreeNode* subTree = parse(data, ptr);
        ptr += 1; //跳过右括号
        return subTree;
    }
    
    TreeNode* parse(string& data, int& ptr) {
        if (data[ptr] == 'X') {
            ptr += 1;
            return nullptr;
        }
        auto cur = new TreeNode(0);
        cur->left = parseSubtree(data, ptr);
        cur->val = parseInt(data, ptr);
        cur->right = parseSubtree(data, ptr);
        return cur;
    }
    
    int parseInt(string& data, int& ptr) {
        int num = 0, flag = 1;
        if (!isdigit(data[ptr])) { //负数
            flag = -1;
            ptr += 1;
        }
        while (isdigit(data[ptr])) {
            num = num*10 + (data[ptr++] - '0');
        }
        return num * flag;
    }
};
```

