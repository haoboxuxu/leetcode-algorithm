class Trie {
public:
    Trie(): chindren(26), isEnd(false) {}
    
    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->chindren[ch] == nullptr) {
                node->chindren[ch] = new Trie();
            }
            node = node->chindren[ch];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = searchHelper(word);
        return node != nullptr && node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = searchHelper(prefix);
        return node != nullptr;
    }
private:
    vector<Trie*> chindren;
    bool isEnd;
    
    Trie* searchHelper(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->chindren[ch] == nullptr) return nullptr;
            node = node->chindren[ch];
        }
        return node;
    }
};
