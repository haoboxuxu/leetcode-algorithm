class Solution {
public:
    bool wordPattern(string p, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) words.push_back(word);
        if (p.size() != words.size()) return false;
        unordered_map<char, string> cs;
        unordered_map<string, char> sc;
        for (int i = 0; i < p.size(); i++) {
            char a = p[i];
            string b = words[i];
            if (cs.count(a) && cs[a] != b) return false;
            cs[a] = b;
            if (sc.count(b) && sc[b] != a) return false;
            sc[b] = a;
        }
        return true;
    }
};