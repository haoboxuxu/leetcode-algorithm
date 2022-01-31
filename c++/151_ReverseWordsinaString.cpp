class Solution {
public:
    string reverseWords(string s) {
        string res;
        reverse(s.begin(), s.end());
        int i = 0;
        while (i < s.size() && s[i] == ' ') i++;
        while (i < s.size()) {
            int k = i;
            while (k < s.size() && s[k] != ' ') k++;
            auto sub = s.substr(i, k - i);
            reverse(sub.begin(), sub.end());
            res += sub + ' ';
            while (k < s.size() && s[k] == ' ') k++;
            i = k;
        }
        res.pop_back();
        return res;
    }
};