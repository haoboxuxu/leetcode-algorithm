class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        auto res = root;
        while (root) {
            auto dummy = new Node(-1), cur = dummy;
            for (auto p = root; p; p = p->next) {
                if (p->left) cur = cur->next = p->left;
                if (p->right) cur = cur->next = p->right;
            } 
            root = dummy->next;
        }
        return res;
    }
};