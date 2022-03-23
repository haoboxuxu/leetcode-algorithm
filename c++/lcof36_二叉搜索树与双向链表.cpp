/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        auto sides = dfs(root);
        sides.second->right = sides.first;
        sides.first->left = sides.second;
        return sides.first;
    }

    pair<Node*, Node*> dfs(Node* root) {
        if (!root->left && !root->right) {
            return {root, root};
        } else if (root->left && root->right) {
            auto lside = dfs(root->left), rside = dfs(root->right);
            lside.second->right = root, root->left = lside.second;
            rside.first->left = root, root->right = rside.first;
            return {lside.first, rside.second};
        } else if (root->left) {
            auto lside = dfs(root->left);
            lside.second->right = root, root->left = lside.second;
            return {lside.first, root};
        } else {
            auto rside = dfs(root->right);
            rside.first->left = root, root->right = rside.first;
            return {root, rside.second};
        }
    }
};
