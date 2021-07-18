class Solution {
public:
    unordered_map<char, int> tmap, wmap; //ori:t中字符的频数  cnt:当前窗口中字符的频数
    
    string minWindow(string s, string t) {
        for (const auto &c : t) {
            ++tmap[c];
        }
        
        int l = 0, r = -1;
        int len = INT_MAX, resL = -1;
        
        while (r < (int)s.size()) {
            if (tmap.find(s[++r]) != tmap.end()) {
                ++wmap[s[r]];
            }
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    resL = l;
                }
                if (tmap.find(s[l]) != tmap.end()) {
                    --wmap[s[l]];
                }
                ++l;
            }
        }
        
        return resL == -1 ? "" : s.substr(resL, len);
    }
    
    bool check() {
        for (const auto &o : tmap) {
            if (wmap[o.first] < o.second) {
                return false;
            }
        }
        return true;
    }
};
