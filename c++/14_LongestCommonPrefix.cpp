class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.empty()) return res;
        for (int i = 0; i < strs[0].size() ; i++) {
            char c = strs[0][i];
            for (auto& str : strs) {
                if (str.size() <= i || str[i] != c) return res;
            }
            res += c;
        }
        return res;
    }
};
