class AllOne {
public:
    struct Node {
        Node *left, *right;
        int val;
        unordered_set<string> s;
        Node(int _val) {
            val = _val;
            left = right = nullptr;
        }
    } *L, *R;

    unordered_map<string, Node*> mp;

    AllOne() {
        L = new Node(INT_MIN), R = new Node(INT_MAX);
        L->right = R, R->left = L;
    }

    Node* add_to_right(Node* node, string key, int val) {
        if (node->right->val == val) {
            node->right->s.insert(key);
        } else {
            auto t = new Node(val);
            t->s.insert(key);
            t->right = node->right, node->right->left = t;
            node->right = t, t->left = node;
        }
        return node->right;
    }

    Node* add_to_left(Node* node, string key, int val) {
        if (node->left->val == val) {
            node->left->s.insert(key);
        } else {
            auto t = new Node(val);
            t->s.insert(key);
            t->left = node->left, node->left->right = t;
            node->left = t, t->right = node;
        }
        return node->left;
    }

    void remove(Node* node) {
        node->left->right = node->right;
        node->right->left = node->left;
        delete node;
    }
    
    void inc(string key) {
        if (!mp.count(key)) {
            mp[key] = add_to_right(L, key, 1);
        } else {
            auto t = mp[key];
            t->s.erase(key);
            mp[key] = add_to_right(t, key, t->val + 1);
            if (t->s.empty()) remove(t);
        }
    }
    
    void dec(string key) {
        if (!mp.count(key)) return;
        auto t = mp[key];
        t->s.erase(key);
        if (t->val > 1) {
            mp[key] = add_to_left(t, key, t->val - 1);
        } else {
            mp.erase(key);
        }
        if (t->s.empty()) remove(t);
    }
    
    string getMaxKey() {
        if (R->left != L) return *R->left->s.begin();
        else return "";
    }
    
    string getMinKey() {
        if (L->right != R) return *L->right->s.begin();
        else return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
