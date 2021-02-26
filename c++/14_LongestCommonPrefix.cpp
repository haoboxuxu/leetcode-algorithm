// sol1
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = (int)strs.size();
        if (len == 0) return "";
        string prefix = strs[0];
        for (int i = 0; i < len; i++) {
            prefix = lcp(prefix, strs[i]);
            if (prefix.length() == 0) break;
        }
        return prefix;
    }
    
    string lcp(const string& s1, const string& s2) {
        int len = (int)min(s1.length(), s2.length());
        int index = 0;
        while (index < len && s1[index] == s2[index]) {
            index++;
        }
        return s1.substr(0, index);
    }
};
// sol2
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = (int)strs.size();
        if (size == 0) return "";
        int len = (int)strs[0].length();
        for (int i = 0; i < len; i++) {
            char c = strs[0][i];
            for (int j = 0; j < size; j++) {
                if (i == strs[j].length() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};