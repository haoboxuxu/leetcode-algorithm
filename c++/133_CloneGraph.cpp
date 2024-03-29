/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> hash;

    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        dfs(node);

        for (auto [a, b] : hash) {
            for (auto neighbor : a->neighbors) {
                b->neighbors.push_back(hash[neighbor]);
            }
        }

        return hash[node];
    }

    void dfs(Node* node) {
        hash[node] = new Node(node->val);
        for (auto neighbor : node->neighbors) {
            if (hash.count(neighbor) == 0) {
                dfs(neighbor);
            }
        }
    }
};
