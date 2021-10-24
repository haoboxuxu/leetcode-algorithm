class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> s2c;
        unordered_map<char, string> c2s;
        int len = s.length();
        int i = 0;
        for (char ch : pattern) {
            if (i >= len) return false;
            int j = i;
            while (j < len && s[j] != ' ') j++;
            string word = s.substr(i, j-i);
            if (s2c.count(word) && s2c[word] != ch) return false;
            if (c2s.count(ch) && c2s[ch] != word) return false;
            s2c[word] = ch;
            c2s[ch] = word;
            i = j + 1;
        }
        return i >= len;
    }
};
