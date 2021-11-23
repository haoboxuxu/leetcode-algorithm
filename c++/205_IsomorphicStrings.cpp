class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        
        int len = (int)s.size();
        for (int i = 0; i < len; i++) {
            char sc = s[i], tc = t[i];
            if ((s2t.count(sc) && s2t[sc] != tc) || (t2s.count(tc) && t2s[tc] != sc)) {
                return false;
            }
            s2t[sc] = tc;
            t2s[tc] = sc;
        }
        return true;
    }
};
