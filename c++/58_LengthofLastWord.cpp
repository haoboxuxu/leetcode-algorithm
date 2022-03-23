class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int k = n - 1;
        while (k >= 0 && s[k] == ' ') k--;
        int j = k;
        while (j >= 0 && s[j] != ' ') j--;
        return k - j;
    }
};