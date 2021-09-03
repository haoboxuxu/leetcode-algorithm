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
