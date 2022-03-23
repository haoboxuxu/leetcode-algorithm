class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isAlphabet(s[i])) i++;
            while (i < j && !isAlphabet(s[j])) j--;
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }

    bool isAlphabet(char c) {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }
};
