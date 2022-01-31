class LRUCache {
public:
    struct Node {
        int key, val;
        Node *left, *right;
        Node(int k, int v): key(k), val(v), left(nullptr), right(nullptr) {}
    }*head, *tail;
    unordered_map<int, Node*> hash;
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->right = tail;
        tail->left = head;
    }
    
    int get(int key) {
        if (hash.count(key) == 0) return -1;
        auto p = hash[key];
        remove(p);
        insert(p);
        return p->val;
    }
    
    void put(int key, int value) {
        if (hash.count(key)) {
            auto p = hash[key];
            p->val = value;;
            remove(p);
            insert(p);
        } else {
            if (hash.size() == cap) {
                auto p = tail->left;
                remove(p);
                hash.erase(p->key);
                delete p;
            }
            auto p = new Node(key, value);
            hash[key] = p;
            insert(p);
        }
    }
    
    void remove(Node* p) {
        p->left->right = p->right;
        p->right->left = p->left;
    }
    
    void insert(Node* p) {
        p->right = head->right;
        p->left = head;
        p->right->left = p;
        p->left->right = p;
    }
};
