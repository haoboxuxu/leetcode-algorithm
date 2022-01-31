class Codec {
public:
    string path;
    string serialize(TreeNode* root) {
        dfs_s(root);
        return path;
    }

    TreeNode* deserialize(string data) {
        int u = 0;
        return dfs_d(data, u);
    }

    void dfs_s(TreeNode* root) {
        if (root == nullptr) {
            path += "#,";
        } else {
            path += to_string(root->val) + ",";
            dfs_s(root->left);
            dfs_s(root->right);
        }
    }

    TreeNode* dfs_d(string& data, int& u) {
        if (data[u] == '#') {
            u += 2;
            return nullptr;
        } else {
            int k = u;
            while (data[u] != ',') u++;
            auto root = new TreeNode(stoi(data.substr(k, u-k)));
            u++;
            root->left = dfs_d(data, u);
            root->right = dfs_d(data, u);
            return root;
        }
    }
};