// sol1
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = 10;
        vector<string> res;
        unordered_map<string, int> mp;
        for (int i = 0; i <= (int)s.length() - len; i++) {
            string sub = s.substr(i, len);
            if (++mp[sub] == 2) {
                res.push_back(sub);
            }
        }
        return res;
    }
};
// sol2
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = 10;
        unordered_map<char, int> bin = {{'A', 0},{'C', 1},{'G', 2},{'T', 3}};
        vector<string> res;
        
        if (s.length() <= len) return res;
        
        int x = 0;
        for (int i = 0; i < len-1; i++) {
            x = (x<<2) | bin[s[i]];
        }
        
        unordered_map<int, int> mp;
        for (int i = 0; i <= (int)s.size() - len; i++) {
            x = ((x<<2) | bin[s[i+len-1]]) & ((1<<(2*len)) - 1);
            if (++mp[x] == 2) {
                res.push_back(s.substr(i, len));
            }
        }
        
        return res;
    }
};
