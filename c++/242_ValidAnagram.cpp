class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> v(26, 0);
        for (auto& c : s) v[c-'a']++;
        for (auto& c : t) {
            if (--v[c-'a'] < 0) return false;
        }
        return true;
    }
};
