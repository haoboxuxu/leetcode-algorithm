class Trie {
public:
    struct Node {
        Node* son[26];
        bool is_end;
        Node() {
            is_end = false;
            for (int i = 0; i < 26; i++) son[i] = nullptr;
        }
    } *root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        auto p = root;
        for (auto c : word) {
            int u = c - 'a';
            if (!p->son[u]) p->son[u] = new Node();
            p = p->son[u];
        }
        p->is_end = true;
    }
    
    bool search(string word) {
        auto p = root;
        for (auto c : word) {
            int u = c - 'a';
            if (!p->son[u]) return false;
            p = p->son[u];
        }
        return p->is_end;
    }
    
    bool startsWith(string prefix) {
        auto p = root;
        for (auto c : prefix) {
            int u = c - 'a';
            if (!p->son[u]) return false;
            p = p->son[u];
        }
        return true;
    }
};